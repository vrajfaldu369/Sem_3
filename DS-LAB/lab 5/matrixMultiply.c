/*  Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
and store result in third matrix and print it. */

#include <stdio.h>
int main() {

    int mat1[3][2], mat2[2][3], result[3][3];
    int i, j, k;

    printf("Enter elements for the first matrix (3x2):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nEnter elements for the second matrix (2x3):\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            result[i][j] = 0;
            
            for(k = 0; k < 2; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("\nThe resulting 3x3 matrix after multiplication is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}