#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head = NULL;
int nodeCount=0;                   //total number of Nodes in the list
int choice, num, pos;
void display();                    // Display the list
void insert(int num);              // choose the type of insertion and Insert an element.
void insert_beg(int num);          // Insertion at beginning
void insert_end(int num);          // Insertion at end
void insert_pos(int num, int pos); // Insertion at a position
void delete();                     // choose the type of deletion and deletes the element
int delete_beg();                  // delete from beginning
int delete_end();                  // delete from end
int delete_pos(int pos);           // delete from a position
void insert(int num)
{
    int choice;
    printf("\n1.Insertion at beginning\n2.Insertion at end\n3.Insertion at a position");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice) // performs specific type of insertion
    {
    case 1:
        insert_beg(num);
        break;
    case 2:
        insert_end(num);
        break;
    case 3:
        printf("\nEnter the position of the element:");
        scanf("%d", &pos);
        insert_pos(num, pos);
        break;
    default:
        printf("\nEnter a valid choice");
        break;
    }
}
void delete()
{
    int choice;
    printf("\n1.Deeletion from beginning\n2.Deletion from end\n3.Deletion from a position");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice) // performs specific type of insertion
    {
    case 1:
        num = delete_beg();
        if (num == -1)
        {
            printf("\nList is empty");
        }
        else
        {
            printf("\nDeleted element =%d", num);
        }
        break;
    case 2:
        num = delete_end(num);
        if (num == -1)
        {
            printf("\nList is empty");
        }
        else
        {
            printf("\nDeleted element =%d", num);
        }
        break;
    case 3:
        printf("\nEnter the position of the element to be deleted:");
        scanf("%d", &pos);
        num = delete_pos(pos);
        if (num == -1)
        {
            printf("\nList is empty");
        }
        else if(num==-2){
            printf("\nEnter a valid position\n");
        }
        else
        {
            printf("\nDeleted element =%d", num);
        }
        break;
    default:
        printf("\nEnter a valid choice");
        break;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("\nList is empty"); // List is empty
    }
    else
    {
        struct Node *temp = head;
        printf("\nList Elements are\n");
        while (temp != NULL) // traversal
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
    }
}
void insert_end(int num)
{
    struct Node *temp = head;
    struct Node *prev;
    if (head == NULL)
    {
        insert_beg(num);
    }
    else
    {
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->link = NULL;
        prev->link = newNode;
        printf("\nElement added at end\n");
    }
    nodeCount++;
}
void insert_beg(int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->link = head;
    head = newNode;
    nodeCount++;
    printf("\nInserted new element successfully");
}
void insert_pos(int num, int pos)
{
    if (pos == 0 || head == NULL)
    {
        insert_beg(num);
    }
    else if(pos>nodeCount-1 || pos<0){
        printf("\nEnter a valid position\n");
    }
    else
    {
        struct Node *temp = head;
        for (int i = 0; i <= pos - 2; i++) // traversing to the node before the node at pos
        {
            temp = temp->link;
        }
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->data = num;
        node->link = temp->link;
        temp->link = node;
        nodeCount++;
        printf("\nInserted new element successfully");
    }
}
int delete_beg()
{
    if (head == NULL)
    {
        return -1; // list is empty
    }
    else
    {
        nodeCount--;
        int num = head->data;
        head = head->link;
        return num;
    }
}
int delete_end()
{
    if (head == NULL)
    {
        return -1; // list is empty
    }
    else if (head->link == NULL) // only 1 element in the list
    { 
        nodeCount--;
        num = head->data;
        head = NULL;
        return num;
    }
    else
    {
        struct Node *temp = head; // points to last element
        struct Node *prev;        // points to second last element
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        int data = temp->data;
        prev->link = NULL;
        nodeCount--;
        return data;
    }
}
int delete_pos(int pos)
{
    int num;
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        if (pos == 0)
        {
            num = delete_beg();
        }
        else if(pos<0 || pos>nodeCount-1){
            return -2;
        }
        else
        {
            struct Node *temp = head; // points to the previous node of the node to be deleted
            for (int i = 0; i <= pos - 2; i++)
            {
                temp = temp->link;
            }
            struct Node *current = temp->link;
            num = current->data;
            temp->link = current->link;
            nodeCount--;
            return num;
        }
    }
}
void main()
{
    printf("Linked List Operations\n");
    bool flag = true;
    while (flag) // Main Menu
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nChoose your option:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be inserted:");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            flag = false;
            break;
        default:
            printf("\nEnter a valid choice");
            break;
        }
    }
}