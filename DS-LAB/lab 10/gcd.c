#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void display(struct Node *head){
    struct Node *curr = head;

    if(curr == NULL){
        printf("List is empty:\n");
        return;
    }

    printf("List: ");
    while (curr != NULL){
        printf("%d -> ",curr->info);
        curr = curr->link;
    }
    printf("NULL\n");
    
}

struct Node* insertEnd(struct Node* head, int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->info = x;
    newNode->link = NULL;

    if(head == NULL){
        head = newNode;
        return head;
    }

    struct Node *curr = head;
    while (curr->link != NULL){
        curr = curr->link;
    }
    curr->link = newNode;
    return head;
}

int find_gcd(int a, int b){
    while (b != 0){
    
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

void insertGCD(struct Node* head){
    struct Node* curr = head;
    if(curr == NULL){
        return;
    }

    while (curr->link != NULL){
    
        struct Node* temp = curr->link; //temp=6
        int gcd = find_gcd(curr->info, temp->info); //gcd=6

        struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
        
        temp2->info = gcd; 
        temp2->link = temp;
        curr->link = temp2;

        curr = curr->link->link;
    }
    
}

void main(){
    struct Node* head = NULL;

    head = insertEnd(head, 18);
    head = insertEnd(head, 6);
    head = insertEnd(head, 10);
    head = insertEnd(head, 3);

    display(head);

    insertGCD(head);

    display(head);
}
