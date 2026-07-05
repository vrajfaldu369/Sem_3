// WAP to sort the array elements using Pointer.

#include <stdio.h>
void sortArray(int *ptr, int size) {

    int i, j, temp;

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(ptr + i) > *(ptr + j)) {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}

int main() {
    int size;
    int arr[100];
    int *ptr = arr;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", (ptr + i));
    }

    sortArray(arr, size);

    printf("\nThe elements after sorting in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}
