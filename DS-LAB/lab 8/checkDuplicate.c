/* Write a program to remove the duplicates nodes from given sorted Linked List. 
 Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
 Output: 1 → 6 → 13 → 27 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *FIRST = NULL;

struct Node* createNode(int info){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

void insertEnd(int info){
    struct Node *newNode = createNode(info);

    if(FIRST == NULL){
        FIRST = newNode;
        return;
    }

    struct Node *temp = FIRST;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = newNode;
}

void removeDuplicates(){
    struct Node *SAVE = FIRST;
    struct Node *duplicate;

    while(SAVE != NULL && SAVE->link != NULL){

        if(SAVE->info == SAVE->link->info){
            duplicate = SAVE->link;
            SAVE->link = duplicate->link;
            free(duplicate);
        }
        else{
            SAVE = SAVE->link;
        }
    }
}

void display(){

    struct Node *temp = FIRST;

    while(temp != NULL){

        printf("%d", temp->info);

        if(temp->link != NULL){
            printf(" -> ");
        }    
        temp = temp->link;
    }
    printf("\n");
}

int main(){

    insertEnd(1);
    insertEnd(1);
    insertEnd(6);
    insertEnd(13);
    insertEnd(13);
    insertEnd(13);
    insertEnd(27);
    insertEnd(27);

    printf("Original Linked List:\n");
    display();

    removeDuplicates();

    printf("Linked List after removing duplicates:\n");
    display();

    return 0;
}