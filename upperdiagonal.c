#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, rows, cols;

    // Input: dimensions
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input. Rows and columns must be positive integers.\n");
        return 1;
    }

    // Step 1: Allocate memory for matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed at row %d\n", i);
            // Free previously allocated memory
            for (j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return 1;
        }
    }

    // Step 2: Input matrix elements
    printf("Enter the elements of the matrix (%d × %d):\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid element input.\n");
                return 1;
            }
        }
    }

    // Step 3: Convert to Upper Diagonal Matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i > j) {
                matrix[i][j] = 0;  // Set elements below main diagonal to 0
            }
        }
    }

    // Step 4: Display the updated matrix
    printf("\nUpper Diagonal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Step 5: Free dynamically allocated memory
    for (i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
