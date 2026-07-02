// Write a program to calculate average of first n numbers.

#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double avg = sum / n;
    printf("%lf", avg);

    return 0;
}