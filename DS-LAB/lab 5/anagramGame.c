#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void sortString(char str[])
{
    int i, j;
    char temp;
    int len = strlen(str);

    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int isAnagram(char str1[], char str2[])
{
    if(strlen(str1) != strlen(str2))
        return 0;

    char temp1[100], temp2[100];

    strcpy(temp1, str1);
    strcpy(temp2, str2);

    sortString(temp1);
    sortString(temp2);

    if(strcmp(temp1, temp2) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n, i, index;
    char words[20][100];
    char userWord[100];

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", words[i]);
    }

    srand(time(0));

    index = rand() % n;

    printf("\nGiven Word: %s\n", words[index]);

    printf("Enter its anagram: ");
    scanf("%s", userWord);

    if(isAnagram(words[index], userWord))
        printf("Correct! '%s' is an anagram of '%s'\n",
               userWord, words[index]);
    else
        printf("Wrong! '%s' is NOT an anagram of '%s'\n",
               userWord, words[index]);

    return 0;
}