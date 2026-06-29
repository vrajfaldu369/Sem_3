#include <stdio.h>
void main(){
    int base, exponent;
    printf("Enter Base And Exponent: ");
    scanf("%d %d",&base, &exponent);
    int res = 1;
    int temp = exponent;
    while (exponent > 0)
    {
        res *= base;
        exponent--;
    }
    printf("%d",res);
    
}