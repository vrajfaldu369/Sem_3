// Write a program to reverse a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node* createNode(int info){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node *FIRST, int info){

    struct Node *newNode = createNode(info);

    if (FIRST == NULL){
        return newNode;
    }

    struct Node *temp = FIRST;

    while (temp->link != NULL){
        temp = temp->link;
    }

    temp->link = newNode;

    return FIRST;
}

struct Node* reverseList(struct Node *FIRST){

    struct Node *prev = NULL;
    struct Node *SAVE = FIRST;
    struct Node *link = NULL;

    while (SAVE != NULL){

        link = SAVE->link;
        SAVE->link = prev;
        prev = SAVE;
        SAVE = link;
    }

    return prev;
}

void display(struct Node *FIRST){

    while (FIRST != NULL){
        printf("%d -> ", FIRST->info);
        FIRST = FIRST->link;
    }
    printf("NULL\n");
}

int main(){

    struct Node *FIRST = NULL;

    FIRST = insertEnd(FIRST, 10);
    FIRST = insertEnd(FIRST, 20);
    FIRST = insertEnd(FIRST, 30);
    FIRST = insertEnd(FIRST, 40);

    printf("Original List:\n");
    display(FIRST);

    FIRST = reverseList(FIRST);

    printf("Reversed List:\n");
    display(FIRST);

    return 0;
}