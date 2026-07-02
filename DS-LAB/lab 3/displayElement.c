// Write a program to read and display n numbers using an array. 

#include "stdio.h"
int main(){
    int n, i;

    printf("Enter size: ");
    scanf("%d",&n);

    int a[n];

    
    printf("Enter elements:\n");
    for(i = 0; i < n; i++){
        printf("Enter element %d: ",(i+1));
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n; i++){
        printf("%d ",a[i]);
    }

    return 0;
}