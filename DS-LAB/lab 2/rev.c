#include <stdio.h>
void main(){
    int n = 123, rev, rem;

    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    printf("%d",rev);
    
}