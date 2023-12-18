package main

import (
	"fmt"
)

func insertSort(values *[]int) {
	a := *values
	for i := 0; i <= len(a)-1; i++ {
		key := a[i]
		j := i - 1
		for j >= 0 && a[j] > key {
			fmt.Println(j)
			a[j+1] = a[j]
			j = j - 1
		}
		a[j+1] = key
	}
}

func main() {
	values := []int{2, 3, 5, 4, 1, 6}
	insertSort(&values)
	fmt.Println(values)
}
