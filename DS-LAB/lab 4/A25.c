// Write a program to delete a number from a given location in an array.

#include "stdio.h"
int main(){
    int a[5] = {1,2,3,4,5};
    int n = 5, pos, i;

    printf("Enter position (1 to %d): ",n+1);
    scanf("%d",&pos);

    for(i = pos - 1; i < n - 1; i++){
        a[i] = a[i+1];
    }
    n--;

    for(i = 0; i < n; i++){
        printf("%d, ",a[i]);
    }

    return 0;
}