/* Write a program to implement a node structure for singly linked list. Read the 
data in a node, print the node. */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

int main(){
    struct Node *first;

    first = (struct Node *) malloc(sizeof(struct Node));

    if(first == NULL){
        printf("Memory allocation Failed!!\n");
        return 1;
    }

    printf("Enter data: ");
    scanf("%d",&first->info);

    first->link = NULL;

    printf("Node data : %d\n",first->info);

    free(first);
    
    return 0;
}
