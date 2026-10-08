#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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

void sortList(struct Node* FIRST) {
    struct Node* i;
    struct Node* j;
    int temp;

    if (FIRST == NULL){
        return;
    }

    for (i = FIRST; i->link != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

void printList(struct Node* FIRST) {
    
    struct Node* temp = FIRST;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {

    insertEnd(45);
    insertEnd(10);
    insertEnd(30);
    insertEnd(25);
    insertEnd(5);

    printf("Original List:\n");
    printList(FIRST);

    sortList(FIRST);

    printf("\nSorted List:\n");
    printList(FIRST);

    return 0;
}
