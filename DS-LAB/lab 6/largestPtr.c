// WAP to find the largest element in the array using Pointer.

#include <stdio.h>
int main(){

    int arr[100], n, i;
    int *ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    int largest = *ptr;

    for(i = 1; i < n; i++)
    {
        if(*(ptr + i) > largest)
        {
            largest = *(ptr + i);
        }
    }
    printf("Largest element = %d\n", largest);

    return 0;
}