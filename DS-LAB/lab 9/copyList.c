// Write a program to copy a linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node* createNode(int info){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;

    return newNode;
}

struct Node *FIRST = NULL;

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

struct Node* copyLists(struct Node *FIRST){
    if(FIRST == NULL){
        return NULL;
    }

    struct Node *newFIRST = createNode(FIRST->info);
    struct Node *newSAVE = newFIRST;
    struct Node *oldSAVE = FIRST->link;

    while(oldSAVE != NULL){
        newSAVE->link = createNode(oldSAVE->info);
        newSAVE = newSAVE->link;
        oldSAVE = oldSAVE->link;
    }

    return newFIRST;
}

void display(struct Node *FIRST){
    while(FIRST != NULL){
        printf("%d -> ",FIRST->info);
        FIRST = FIRST->link;
    }
    printf("NULL\n");
}

int main(){
    struct Node *copiedList = NULL;

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printf("Original List: ");
    display(FIRST);

    copiedList = copyLists(FIRST);

    printf("Copied List: ");
    display(copiedList);

    return 0;
}
