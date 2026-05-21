// Insertion sort

fn insertion_sort(array: &mut [i32], number: i32) {
    // [5; 2; 4; 6; 1; 3]
    let mut i: i32 = 0;
    while i < number {
        let value = array[i as usize];

        let mut j = i - 1;
        while j >= 0 && array[j as usize] > value {
            array[(j + 1) as usize] = array[j as usize];
            j -= 1;
        }
        array[(j + 1) as usize] = value;
        i += 1;
    }
}

// Merge sort

fn merge(array: &mut [i32], start: usize, mid: usize, end: usize) {
    print!("start: {:?}, mid: {:?}, end: {:?}\n", start, mid, end);
    let left_length: usize = mid - start + 1;
    print!("left length : {:?}\n", left_length);
    let right_length: usize = end - mid;
    print!("right length : {:?}\n", right_length);

    let mut left: Vec<i32> = vec![0; left_length];
    let mut right: Vec<i32> = vec![0; right_length];

    for i in 0..left_length {
        left[i] = array[start + i]
    }

    print!("{:?}\n", left);

    for j in 0..right_length {
        right[j] = array[mid + 1 + j]
    }

    print!("{:?}\n", right);

    let mut i: usize = 0;
    let mut j: usize = 0;
    let mut k: usize = start;

    while i < left_length && j < right_length {
        if left[i] <= right[j] {
            array[k] = left[i];
            i += 1;
        } else {
            array[k] = right[j];
            j += 1;
        }

        k += 1;
    }

    while i < left_length {
        array[k] = left[i];
        i += 1;
        k += 1;
    }
    while j < right_length {
        array[k] = right[j];
        j += 1;
        k += 1;
    }
}

fn merge_sort(array: &mut [i32], start: usize, end: usize) {
    if start >= end {
        return;
    }

    let mid: usize = (start + end) / 2;
    print!("mid: {:?}\n", mid);
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);
    merge(array, start, mid, end)
}

fn main() {
    let mut test = [12, 3, 7, 9, 14, 6, 11, 2];
    merge_sort(&mut test, 0, 7);
    print!("{:?}", test);
}
