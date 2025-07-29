#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, nonZero, i;

    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &nonZero);

    // Allocate memory for full matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
        matrix[i] = (int *)calloc(cols, sizeof(int));  // calloc initializes to 0

    // Input non-zero values
    printf("Enter row, column and value for each non-zero element:\n");
    for (i = 0; i < nonZero; i++) {
        int r, c, val;
        scanf("%d %d %d", &r, &c, &val);
        if (r < rows && c < cols)
            matrix[r][c] = val;
        else
            printf("Invalid index: %d %d\n", r, c);
    }

    // Display full matrix
    printf("Non-Sparse (Full) Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
