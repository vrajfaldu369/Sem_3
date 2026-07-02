//  Write a program to find whether the array contains a duplicate number or not.

#include <stdio.h>
int hasDuplicate(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    if (hasDuplicate(arr, size)) {
        printf("The array contains duplicate numbers.\n");
    } else {
        printf("The array does not contain any duplicate numbers.\n");
    }

    return 0;
}
