// Write a program to insert a number at a given location in an array.

#include "stdio.h"
int main(){
    int a[5] = {1,2,3,4,5};
    int n = 5, num, pos, i;
    printf("Enter no. to insert: ");
    scanf("%d",&num);

    printf("Enter position (1 to %d): ",n+1);
    scanf("%d",&pos);
    
    for (i = n; i >= pos; i--)
    {
        a[i] = a[i-1];
    }
    a[pos-1] = num;
    n++;
    
    for(i = 0; i < n; i++){
        printf("%d, ",a[i]);
    }

    return 0;
}