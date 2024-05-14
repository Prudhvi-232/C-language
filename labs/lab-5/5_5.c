#include <stdio.h>

void inputMatrix(int matrix[][10], int rows, int cols) {
    printf("Enter matrix elements row by row:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][10], int rows, int cols, int result[][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int choice, rows, cols;
    int matrix1[10][10], matrix2[10][10], result[10][10];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter matrix 1:\n");
    inputMatrix(matrix1, rows, cols);

    printf("Enter matrix 2:\n");
    inputMatrix(matrix2, rows, cols);

    printf("Menu:\n");
    printf("1. Addition of two matrices\n");
    printf("2. Subtraction of two matrices\n");
    printf("3. Multiplication of two matrices\n");
    printf("4. Transpose of a matrix\n");
    printf("5. Addition of specific rows from two matrices\n");
    printf("6. Addition of specific columns from two matrices\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMatrices(matrix1, matrix2, result, rows, cols);
            printMatrix(result, rows, cols);
            break;
        case 2:
            subtractMatrices(matrix1, matrix2, result, rows, cols);
            printMatrix(result, rows, cols);
            break;
        case 3:
            multiplyMatrices(matrix1, matrix2, result, rows, cols, cols);
            printMatrix(result, rows, cols);
            break;
        case 4:
            transposeMatrix(matrix1, rows, cols, result);
            printMatrix(result, cols, rows);
            break;
        case 5:
            int row1, row2;
            printf("Enter the rows to add (1-%d): ", rows);
            scanf("%d %d", &row1, &row2);
            if (row1 >= 1 && row2 >= 1 && row1 <= rows && row2 <= rows) {
                int rowResult[10];
                for (int i = 0; i < cols; i++) {
                    rowResult[i] = matrix1[row1 - 1][i] + matrix2[row2 - 1][i];
                }
                printf("Result of addition of row %d and row %d:\n", row1, row2);
                for (int i = 0; i < cols; i++) {
                    printf("%d\t", rowResult[i]);
                }
            } else {
                printf("Invalid row numbers.\n");
            }
            break;
        case 6:
            int col1, col2;
            printf("Enter the columns to add (1-%d): ", cols);
            scanf("%d %d", &col1, &col2);
            if (col1 >= 1 && col2 >= 1 && col1 <= cols && col2 <= cols) {
                int colResult[10];
                for (int i = 0; i < rows; i++) {
                    colResult[i] = matrix1[i][col1 - 1] + matrix2[i][col2 - 1];
                }
                printf("Result of addition of column %d and column %d:\n", col1, col2);
                for (int i = 0; i < rows; i++) {
                    printf("%d\n", colResult[i]);
                }
            } else {
                printf("Invalid column numbers.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
