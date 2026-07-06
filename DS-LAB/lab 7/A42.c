/* Write a menu driven program to implement following operations on the singly 
linked list.  
 Insert a node at the front of the linked list. 
 Display all nodes. 
 Delete a first node of the linked list. 
 Insert a node at the end of the linked list. 
 Delete a last node of the linked list. 
 Delete a node from specified position. 
 Count the no. of nodes in the linked list. */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insertAtFirst(){

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->info);

    newNode->link = first;

    first = newNode;

    printf("Node inserted at first\n");
}

void display(){
    struct Node *save = first;

    if (first == NULL){
        printf("List is empty\n");
        return;
    }

    printf("Linked list: ");
    while (save != NULL){
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

void deleteAtStart(){

    struct Node *temp;

    if (first == NULL){
        printf("List Is Empty\n");
        return;
    }

    temp = first;
    first = first->link;

    free(temp);

    printf("First node deleted\n");
}

void insertAtEnd(){

    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->info);

    newNode->link = NULL;

    if (first == NULL){
        first = newNode;
    }
    else{
        temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
    printf("Node inserted At the end\n");
}

void deleteAtEnd(){

    struct Node *temp, *pre;

    if (first == NULL){
        printf("List is empty");
        return;
    }

    if (first->link == NULL){
        free(first);
        first = NULL;
    }
    else{
        temp = first;

        while (temp->link != NULL)
        {
            pre = temp;
            temp = temp->link;
        }
        pre->link = NULL;
        free(temp);
    }

    printf("Last node deleted\n");
}

void deletePosition(){

    int pos, i;
    struct Node *temp, *prev;

    if (first == NULL){
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1){
        deleteAtStart();
        return;
    }

    temp = first;

    for (i = 1; i < pos && temp != NULL; i++){
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL){
        printf("Invalid Position.\n");
        return;
    }

    prev->link = temp->link;
    free(temp);

    printf("Node deleted from position %d.\n", pos);
}

void countNodes(){

    int count = 0;
    struct Node *temp = first;

    while (temp != NULL){
        count++;
        temp = temp->link;
    }
    printf("Total nodes: %d \n", count);
}

int main(){

    int choice;

    do
    {
        printf("1. Insert at first.\n");
        printf("2. Display all nodes: \n");
        printf("3. Delete first node: \n");
        printf("4. Insert at end: \n");
        printf("5. Delete last node: \n");
        printf("6. Delete node at a specific position: \n");
        printf("7. Count total nodes: \n");
        printf("8. Exit\n");

        printf("Enter choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtFirst();
            break;

        case 2:
            display();
            break;

        case 3:
            deleteAtStart();
            break;

        case 4:
            insertAtEnd();
            break;

        case 5:
            deleteAtEnd();
            break;

        case 6:
            deletePosition();
            break;

        case 7:
            countNodes();
            break;

        case 8:
            printf("Exiting....\n");
            break;

        default:
            printf("Invalid choice! Enter a number between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}