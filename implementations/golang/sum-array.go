package main

func Sum(values *[]int) int {
	a := *values
	sum := 0
	for i := 0; i <= len(a)-1; i++ {
		sum = sum + a[i]
	}
	return sum
}
