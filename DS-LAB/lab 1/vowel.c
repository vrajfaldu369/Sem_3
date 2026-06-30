//WAP to determine whether the entered character is vowel or not.

#include <stdio.h>
void main(){
    char ch;
    printf("Enter character: ");
    scanf("%c",&ch);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        printf("%c is Vowel",ch);
    }
    else{
        printf("%c is not Vowel, it is Consonant",ch);
    }
}