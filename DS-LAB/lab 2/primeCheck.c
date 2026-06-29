#include <stdio.h>
void main(){
    int n = 15, check;

    if(n <= 1){
        check = 0;
    }
    else{
        for(int i = 2; i <= n-1; i++){
            if(n % i ==0){
                check = 1;
                break;
            }
        }
    }
    if(check ==1){
        printf("Not Prime");
    }
    else{
        printf("Prime");
    }
}