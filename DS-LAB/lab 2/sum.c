#include <stdio.h>
void main(){
    int sum = 0, n = 3;
    for(int i = 1; i <= n; i++){
        sum += (i * (i - 1)) / 2;
    }
    printf("%d",sum);
}