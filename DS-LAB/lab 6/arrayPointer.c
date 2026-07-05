// WAP to get and print the array elements using Pointer.

#include <stdio.h>
int main(){
    int arr[100], n, *ptr, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    printf("\nArray elements are:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(ptr + i));
    }

    return 0;
}