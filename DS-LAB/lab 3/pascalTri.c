// Pascal Triangle

#include <stdio.h>
void main() {
    int rows = 5;

    for (int i = 0; i < rows; i++) {
        for (int space = 1; space <= rows - i; space++) {
            printf("  ");
        }

        int val = 1;
        for (int j = 0; j <= i; j++) {
            printf("%2d  ", val);

            val = val * (i - j) / (j + 1);
        }
        printf("\n");
    }
    
}