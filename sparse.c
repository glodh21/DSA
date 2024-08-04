#include <stdio.h>

// Function to convert matrix to sparse matrix
void convertToSparse(int matrix[4][5], int sparse[20][3]) {
    int i, j, k = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[k][2] = -1; // End marker
}

// Function to print the sparse matrix
void printSparse(int sparse[20][3]) {
    int i = 0;
    while (sparse[i][2] != -1) {
        printf("(%d, %d, %d)\n", sparse[i][0], sparse[i][1], sparse[i][2]);
        i++;
    }
}

void transposeSparse(int sparse[20][3], int transposed[20][3]) {
    int i, k = 0;
    
    // Find the number of non-zero elements
    while (sparse[k][2] != -1) {
        k++;
    }

    // Transpose the elements
    for (i = 0; i < k; i++) {
        transposed[i][0] = sparse[i][1];
        transposed[i][1] = sparse[i][0];
        transposed[i][2] = sparse[i][2];
    }
    transposed[k][2] = -1; // End marker
}

int main() {
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int sparse[20][3];
    int transposed[20][3];

    convertToSparse(matrix, sparse);
    printSparse(sparse);

    transposeSparse(sparse,transposed);

    printf("\nTransposed Sparse Matrix:\n");
    printSparse(transposed);

    return 0;
}