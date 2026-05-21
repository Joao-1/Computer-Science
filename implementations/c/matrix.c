// ! Matrix with a single dimension array

// Row-major order    -> s + (n(i - s)) + (j - s)
// Column-major order -> s + (m(j - s)) + (i - s)
// s = start index
// n = number of columns
// m = number of rows
// i = row index
// j = column index

#include <stdio.h>

int main() {
    // Matrix with 4 rows and 3 columns (Row-major)
    int rowMatrix[12] = {
        1,  2,  3,
        4,  5,  6,
        7,  8,  9,
        10, 11, 12
    };

    // Get the value "4" in the matrix
    int rowValue = get(rowMatrix, "r", 4, 3, 1, 0);

    printf("Row-major matrix value: %d\n", rowValue);

    // Matrix with 4 rows and 3 columns (Column-major)
    int columnMatrix[12] = {
        1, 4, 7, 10,
        2, 5, 8, 11,
        3, 6, 9, 12
    };

    // Get the value "4" in the matrix
    int columnValue = get(columnMatrix, "c", 4, 3, 1, 0);

    printf("Row-major matrix value: %d\n", columnValue);
}

// This function return the element in the row and column provided in the matrix. 
// Assume that the matrix is a single dimension array and as C is a language with 0-based index, the row and column are also 0-based.
int get(int *matrix, const char *type, int rows, int columns, int row, int column) {
    if (strcmp(type, "r") == 0) { 
        return matrix[columns * row + column]; 
    } else if (strcmp(type, "c") == 0) { 
        return matrix[rows * column + row];
    } else {
        return -1; 
    }
}