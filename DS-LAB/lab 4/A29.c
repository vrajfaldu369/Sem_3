// Write a program to merge two unsorted arrays.

#include <stdio.h>
int main() {
    int arr1[] = {38, 12, 24, 16};
    int arr2[] = {20, 5, 30};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int n3 = n1 + n2;
    int merged[100];
    
    int i, j, temp;

    for (i = 0; i < n1; i++) {
        merged[i] = arr1[i];
    }

    for (j = 0; j < n2; j++) {
        merged[n1 + j] = arr2[j];
    }

    printf("Merged unsorted array: ");
    for (i = 0; i < n3; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    for (i = 0; i < n3 - 1; i++) {
        for (j = 0; j < n3 - i - 1; j++) {
            if (merged[j] > merged[j + 1]) {
                temp = merged[j];
                merged[j] = merged[j + 1];
                merged[j + 1] = temp;
            }
        }
    }

    printf("Merged and sorted array: ");
    for (i = 0; i < n3; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}