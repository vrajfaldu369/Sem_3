/* Write a program to insert a number in an array that is already sorted in an 
ascending order. */

#include <stdio.h>
int main() {
    int arr[6] = {12, 16, 20, 24, 30, 38}; 
    int n = 6;
    int num, i;

    printf("Original sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    i = n - 1;
    while (i >= 0 && arr[i] > num) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = num;
    n++;

    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}