/*
Find the transpose of a matrix.
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows, cols;
    int *cells;
} Matrix;
static int read_matrix(Matrix *matrix) {
    if (scanf("%d %d", &matrix->rows, &matrix->cols) != 2 || matrix->rows <= 0 ||
        matrix->cols <= 0) {
        return 0;
    }
    if ((size_t)matrix->rows > SIZE_MAX / sizeof(int) / (size_t)matrix->cols) {
        return 0;
    }
    size_t count = (size_t)matrix->rows * matrix->cols;
    matrix->cells = malloc(count * sizeof(int));
    if (!matrix->cells) {
        return 0;
    }
    for (size_t i = 0; i < count; i++) {
        if (scanf("%d", &matrix->cells[i]) != 1) {
            free(matrix->cells);
            return 0;
        }
    }
    return 1;
}
static int at(const Matrix *matrix, int row, int column) {
    return matrix->cells[(size_t)row * matrix->cols + column];
}

int main(void) {
    Matrix a;
    if (!read_matrix(&a)) {
        return 1;
    }
    for (int c = 0; c < a.cols; c++) {
        for (int r = 0; r < a.rows; r++) {
            printf("%s%d", r ? " " : "", at(&a, r, c));
        }
        putchar('\n');
    }
    free(a.cells);
    return 0;
}
