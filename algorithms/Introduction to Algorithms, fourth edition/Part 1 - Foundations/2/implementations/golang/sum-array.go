package main

import (
	"fmt"
)

func Sum(values *[]int) int {
	a := *values
	sum := 0
	for i := 0; i <= len(a)-1; i++ {
		sum = sum + a[i]
	}
	return sum
}

func main() {
	values := []int{2, 3, 5, 4, 1, 6}
	result := Sum(&values)
	fmt.Println(result)
}
