#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
int nodeCount = 0;
void insert();
void delete();
void display();
void insertBeg(int num);
void insertEnd(int num);
void insertPos(int num, int pos);
void main()
{
    int op, num, exit = 0;
    printf("\nCircular Queue Operations\n");
    while (exit == 0)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit = 1;
            break;
        default:
            printf("\nEnter a valid choice\n");
            break;
        }
    }
}
void insert()
{
    int num;
    int op, pos;
    printf("\n1.Insertion at beginning\n2.Insertion at end\n3.Insertion at a position\nEnter your choice:");
    scanf("%d", &op);
    printf("\nEnter the number to be inserted:");
    scanf("%d", &num);
    switch (op)
    {
    case 1:
        insertBeg(num);
        break;
    case 2:
        insertEnd(num);
        break;
    case 3:
        printf("\nEnter the position:");
        scanf("%d", &pos);
        insertPos(num, pos);
        break;
    default:
        printf("\nEnter a valid choice\n");
        break;
    }
}
void insertBeg(int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    if (head == NULL && tail == NULL)
    {
        // List is empty
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
    }
    else
    {
        // List is not empty
        newNode->next = head;
        head = newNode;
        // Making pointer of last node to point to current first node
        tail->next = newNode;
    }
    nodeCount++;
    printf("\nInsertion done\n");
}
void insertEnd(int num)
{
    if (nodeCount == 0)
    {
        // List is empty
        insertBeg(num);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;
        // Making new node to point to first Node
        newNode->next = head;
        // Making current last node to point to new Node
        tail->next = newNode;
        // Making tail as new Node
        tail = newNode;
        nodeCount++;
        printf("\nInserted successfully");
    }
}
void insertPos(int num, int pos)
{
    if (pos < 0 || pos > nodeCount)
    {
        printf("\nInvalid position");
    }
    else if (pos == 0)
    {
        // insert at beginning
        insertBeg(num);
    }
    else if (num == nodeCount)
    {
        // insert at end
        insertEnd(pos);
    }
    else
    {
        // traversing to the node
        struct Node *prev = head;
        for (int i = 1; i <= pos - 1; i++)
        {
            prev = prev->next;
        }
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        // Arranging links
        newNode->data = num;
        newNode->next = prev->next;
        prev->next = newNode;
        nodeCount++;
        printf("\nInsertion done");
    }
}
void delete()
{
}
void display()
{
    if (head == NULL && tail == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\nList elements are\n");
        // printing first element alone
        printf("%d\t", temp->data);
        temp = temp->next;
        while (temp != head)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}