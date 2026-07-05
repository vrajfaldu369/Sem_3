// WAP to calculate the sum of n numbers using Pointer

#include <stdio.h>
int main(){
    int arr[100], n, i, sum = 0;
    int *ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }

    for(i = 0; i < n; i++)
    {
        sum = sum + *(ptr + i);
    }

    printf("Sum = %d\n", sum);

    return 0;
}