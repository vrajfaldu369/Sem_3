#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *head = NULL;

void insertAtEnd(int info){

    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;

    if (head == NULL)
        head = newNode;
    else{
    
        temp = head;
        while (temp->link != NULL)
            temp = temp->link;

        temp->link = newNode;
    }
}

void display(){

    struct Node *temp = head;

    while (temp != NULL){
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

void swapPairs(){

    if (head == NULL || head->link == NULL)
        return;

    struct Node *prev = NULL;
    struct Node *curr = head;

    head = head->link; // New head

    while (curr != NULL && curr->link != NULL){
    
        struct Node *link2 = curr->link;
        struct Node *linkPair = link2->link;

        // Swap links
        link2->link = curr;
        curr->link = linkPair;

        // Connect previous pair
        if (prev != NULL)
            prev->link = link2;

        prev = curr;
        curr = linkPair;
    }
}

int main(){
    
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);

    printf("Original List:\n");
    display();

    swapPairs();

    printf("\nList after swapping consecutive nodes:\n");
    display();

    return 0;
}