/* Read n numbers in an array then read two different numbers, replace 1st 
number with 2nd number in an array and print its index and final array. */

#include <stdio.h>
int main() {
    int n, i, n1, n2;
    int found = 0;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter 1st number: ");
    scanf("%d", &n1);
    printf("Enter 2nd number: ");
    scanf("%d", &n2);

    printf("\n--- Results ---\n");
    printf("Indices where replacement occurred: ");
    for(i = 0; i < n; i++) {
        if(arr[i] == n1) {
            arr[i] = n2;
            printf("%d ", i);
            found = 1;
        }
    }
    
    if(!found) {
        printf("Number %d not found in the array", n1);
    }
    printf("\n");

    printf("Final array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}