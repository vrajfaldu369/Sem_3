// WAP to check whether 2 singly linked lists are same or not.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

int isIdentical(struct Node *FIRST1, struct Node *FIRST2){

    struct Node *SAVE1 = FIRST1;
    struct Node *SAVE2 = FIRST2;

    while(SAVE1 != NULL && SAVE2 != NULL){
        if(SAVE1->info != SAVE2->info){
            return 0;
        }
        
        SAVE1 = SAVE1->link;
        SAVE2 = SAVE2->link;
    }   
    return (SAVE1 == NULL && SAVE2 == NULL);
}

struct Node *createNode(int info){

    struct Node *newNode = (struct Node* )malloc(sizeof(struct Node));
    
    if(newNode == NULL){
        printf("Memory Not alloted");
        exit(1);
    }
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

int main(){
    struct Node* first1 = createNode(10);
    first1->link = createNode(20);
    first1->link->link = createNode(30);

    struct Node* first2 = createNode(10);
    first2->link = createNode(20);
    first2->link->link = createNode(30);

    if(isIdentical(first1,first2)){
        printf("Linked lists are same");
    }
    else{
        printf("Linked lists are not same");
    }

    struct Node* temp;
    while(first1 != NULL){
        temp = first1;
        first1 = first1->link;
        free(temp);
    }
    while(first2 != NULL){
        temp = first2;
        first2 = first2->link;
        free(temp);
    }
    
    return 0;
}
