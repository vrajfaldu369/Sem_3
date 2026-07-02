// Write a program to calculate sum of numbers from m to n. 

#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < n; i++) {

        // Add each element to sum
        sum += arr[i];
    }
  
    printf("%d", sum);

    return 0;
}