/* Write a program to delete a number from an array that is already sorted in an 
ascending order. */

#include <stdio.h>
int main() {
    int arr[100] = {12, 16, 20, 24, 30, 38};
    int n = 6;
    int target, i, found = 0, index;

    printf("Original sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the number to delete: ");
    scanf("%d", &target);

    for(i = 0; i < n; i++) {
        if(arr[i] == target) {
            index = i;
            found = 1;
            break;
        }
        if(arr[i] > target) {
            break;
        }
    }

    if(found) {
        for(i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        printf("Array after deletion: ");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}