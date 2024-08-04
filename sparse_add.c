#include<stdio.h>
#define MAX_ELEMENTS 20

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

void addSparseMatrices(int sparse1[20][3], int sparse2[20][3], int result[20][3]) {
    int i = 0, j = 0, k = 0;

    while (sparse1[i][0] != -1 && sparse2[j][0] != -1) {
        if (sparse1[i][0] < sparse2[j][0] ||
            (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1])) {
            result[k][0] = sparse1[i][0];
            result[k][1] = sparse1[i][1];
            result[k][2] = sparse1[i][2];
            i++;
        } else if (sparse1[i][0] > sparse2[j][0] ||
                   (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1])) {
            result[k][0] = sparse2[j][0];
            result[k][1] = sparse2[j][1];
            result[k][2] = sparse2[j][2];
            j++;
        } else { // sparse1[i][0] == sparse2[j][0] && sparse1[i][1] == sparse2[j][1]
            result[k][0] = sparse1[i][0];
            result[k][1] = sparse1[i][1];
            result[k][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
        }
        k++;
    }

    // Copy remaining elements of sparse1, if any
    while (sparse1[i][0] != -1) {
        result[k][0] = sparse1[i][0];
        result[k][1] = sparse1[i][1];
        result[k][2] = sparse1[i][2];
        i++;
        k++;
    }

    // Copy remaining elements of sparse2, if any
    while (sparse2[j][0] != -1) {
        result[k][0] = sparse2[j][0];
        result[k][1] = sparse2[j][1];
        result[k][2] = sparse2[j][2];
        j++;
        k++;
    }

    result[k][0] = -1; // End marker for result sparse matrix
}


int main() {
    int matrix1[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int matrix2[4][5] = {
        {0, 4, 0, 0, 4},
        {0, 6, 0, 0, 9},
        {0, 0, 7, 0, 0},
        {0, 2, 0, 4, 0}
    };



    int sparse1[20][3];
    int sparse2[20][3];
    int result[MAX_ELEMENTS][3];



    convertToSparse(matrix1, sparse1);
    printf("First sparse Matrix\n");
    printSparse(sparse1);

    convertToSparse(matrix2, sparse2);
     printf("Second sparse Matrix\n");
    printSparse(sparse2);


     addSparseMatrices(sparse1, sparse2, result);

    // Print resultant sparse matrix
    printf("\nResultant Sparse Matrix (Sum of Matrix1 and Matrix2):\n");
    printSparse(result);

    
    return 0;

}