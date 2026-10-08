#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *head = NULL;

// Insert at end
void insert(int info)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        temp = head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}

void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

int countNodes()
{
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void swapKth(int k)
{
    int n = countNodes();

    if (k > n || k <= 0)
    {
        printf("Invalid value of K\n");
        return;
    }

    if (2 * k - 1 == n)
        return; // Same node

    struct Node *xPrev = NULL, *x = head;
    for (int i = 1; i < k; i++)
    {
        xPrev = x;
        x = x->link;
    }

    struct Node *yPrev = NULL, *y = head;
    for (int i = 1; i < n - k + 1; i++)
    {
        yPrev = y;
        y = y->link;
    }

    // Update previous nodes
    if (xPrev != NULL)
        xPrev->link = y;
    else
        head = y;

    if (yPrev != NULL)
        yPrev->link = x;
    else
        head = x;

    // Swap link pointers
    struct Node *temp = x->link;
    x->link = y->link;
    y->link = temp;
}

int main()
{
    int k;

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    printf("Original List:\n");
    display();

    printf("Enter value of K: ");
    scanf("%d", &k);

    swapKth(k);

    printf("List after swapping:\n");
    display();

    return 0;
}