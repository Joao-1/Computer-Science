package main

import "testing"

func TestInsertSort(t *testing.T) {
	values := []int{2, 3, 5, 4, 1, 6}

	InsertSort(&values)
}
