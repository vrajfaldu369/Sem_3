/* Write a program to find position of the smallest number & the largest number 
from given n numbers. */

#include <stdio.h>
int main() {
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int small_pos = 0;
    int large_pos = 0;
    
    for(i = 1; i < n; i++) {
        if(arr[i] < arr[small_pos]) {
            small_pos = i;
        }
        if(arr[i] > arr[large_pos]) {
            large_pos = i;
        }
    }
    
    printf("\nSmallest number is %d at position: %d\n", arr[small_pos], small_pos);
    printf("Largest number is %d at position: %d\n", arr[large_pos], large_pos);
    
    return 0;
}
