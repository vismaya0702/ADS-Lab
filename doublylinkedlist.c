#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void insertionBeg(int num);
void insertionEnd(int num);
void insertPos(int pos, int num);
int deleteBeg();
int deleteEnd();
int deletePos(int pos);
void display();
void insert();
void delete();

// insertion_at_beginning
void insertionBeg(int num)
{
    struct Node *newnode = (struct Node *)(malloc(sizeof(struct Node)));
    newnode->data = num;
    if (head == NULL)
    { // list is empty
        head = newnode;
        tail = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else
    {
        struct Node *temp = head;
        head = newnode;
        newnode->prev = NULL;
        newnode->next = temp;
        temp->prev = newnode;
    }
    printf("\nInsertion Successful\n");
}
void delete()
{
    int opcode, data, pos;
    printf("\n1.Deletion from beginning\n2.Deletion from end\n3.Deletion from a position\nEnter the operation:\n");
    scanf("%d", &opcode);
    switch (opcode)
    {
    case 1:
        data = deleteBeg();
        if (data == -1)
        {
            printf("\nList is empty");
        }
        else
        {
            printf("\nDeleted value is %d", data);
        }
        break;
    case 2:
        data = deleteEnd();
        if (data == -1)
        {
            printf("\nList is empty");
        }
        else
        {
            printf("\nDeleted value is %d", data);
        }
        break;
    case 3:
        printf("\nEnter the position:\n");
        scanf("%d", &pos);
        data = deletePos(pos);
        if (data == -1)
        {
            printf("\nList is empty");
        }
        else
        {
            printf("\nDeleted value is %d", data);
        }
        break;
    default:
        printf("\nEnter a valid choice\n");
        break;
    }
}
void insert()
{
    int opcode, data, pos;
    printf("\n1.Insertion at beginning\n2.Insertion at end\n3.Insertion at a position\nEnter the operation:\n");
    scanf("%d", &opcode);
    printf("\nEnter the data to be inserted:\n");
    scanf("%d", &data);
    switch (opcode)
    {
    case 1:
        insertionBeg(data);
        break;
    case 2:
        insertionEnd(data);
        break;
    case 3:
        printf("\nEnter the position:\n");
        scanf("%d", &pos);
        insertPos(pos, data);
        break;
    default:
        printf("\nEnter a valid choice\n");
        break;
    }
}
void display()
{

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        struct Node *temp = head;
        printf("\nList elements are\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
// insertion_at_end
void insertionEnd(int num)
{
    if (head == NULL) // List is empty
    {
        insertionBeg(num);
    }
    else
    {
        struct Node *newNode = malloc(sizeof(struct Node *));
        newNode->data = num;
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        printf("\nInsertion Successful\n");
    }
}
// Insertion at a position
void insertPos(int pos, int num)
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        struct Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        struct Node *nextNode = temp->next;
        struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
        newNode->data = num;
        newNode->prev = temp;
        newNode->next = nextNode;
        temp->next = newNode;
        nextNode->prev = newNode;
        printf("\nInserted Successfully\n");
    }
}
int deleteBeg()
{
    int num;
    if (head == NULL)
    {
        return -1;
    }
    else if (head == tail)
    {
        num = head->data;
        head = NULL;
        tail = NULL;
        return num;
    }
    else
    {
        struct Node *first = head;
        struct Node *second;
        second = first->next;
        second->prev = NULL;
        head = second;
        return first->data;
    }
}
int deleteEnd()
{
    int num;
    if (head == NULL)
    {
        return -1;
    }
    else if (head == tail)
    {
        num = head->data;
        head = NULL;
        tail = NULL;
        return num;
    }
    else
    {
        struct Node *last = tail;
        struct Node *prev = last->prev;
        prev->next = NULL;
        tail = prev;
        return last->data;
    }
}
int deletePos(int pos){
    if(head==NULL){
        return -1;
    }
    else{
        struct Node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        struct Node* current=temp->next;
        struct Node* nextNode=current->next;
        temp->next=nextNode;
        nextNode->prev=current;
        return current->data;

    }
}
void main()
{
    printf("\nDoubly Linked List\n");
    int flag = 1, opcode;
    while (flag == 1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\nEnter the operation:\n");
        scanf("%d", &opcode);
        switch (opcode)
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
            flag = 0;
            break;
        default:
            printf("\nEnter a valid choice\n");
            break;
        }
    }
}