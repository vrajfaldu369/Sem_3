/* Write a program to delete duplicate numbers from an array. */

#include <stdio.h>
int main() {
    int arr[10] = {12, 16, 16, 20, 24, 24, 24, 30, 38, 38};
    int n = 10;
    int i;

    printf("Original array with duplicates: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (n > 1) {
        int unique_index = 0;

        for (i = 1; i < n; i++) {
            if (arr[i] != arr[unique_index]) {
                unique_index++;
                arr[unique_index] = arr[i];
            }
        }

        n = unique_index + 1;
    }

    printf("Array after removing duplicates: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}