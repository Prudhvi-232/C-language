#include <stdio.h>
void rotateImage(int matrix[4][4], int n) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

void printMatrix(int matrix[4][4], int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[4][4];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("number in %d row and %d column:",(i+1),(j+1));
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, n);

    rotateImage(matrix, n);

    printf("\nRotated Matrix:\n");
    printMatrix(matrix, n);

    return 0;
}





// #include <stdio.h>
// #include <stdlib.h>  // Include the standard library for dynamic memory allocation

// void rotateImage(int **matrix, int n) {
//     // Your rotation logic here
// }

// void printMatrix(int **matrix, int n) {
//     // Your printing logic here
// }

// int main() {
//     int n;

//     printf("Enter the size of the square matrix: ");
//     scanf("%d", &n);

//     // Dynamically allocate memory for the matrix
//     int **matrix = (int **)malloc(n * sizeof(int *));
//     for (int i = 0; i < n; i++) {
//         matrix[i] = (int *)malloc(n * sizeof(int));
//     }

//     printf("Enter the elements of the matrix:\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &matrix[i][j]);
//         }
//     }

//     printf("\nOriginal Matrix:\n");
//     printMatrix(matrix, n);

//     rotateImage(matrix, n);

//     printf("\nRotated Matrix:\n");
//     printMatrix(matrix, n);

//     // Free dynamically allocated memory when done
//     for (int i = 0; i < n; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);

//     return 0;
// }
