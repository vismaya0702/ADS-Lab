#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void display();

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void main()
{
    int is_running = 1, ch;
    while (is_running)
    {
        printf("\n----Queue Using Linked List----\n");
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            is_running = 0;
            break;
        default:
            printf("\nWrong Choice :(\n");
            break;
        }
    }
}

void enqueue()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));

    int data;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue Empty!!\n");
    }
    else
    {
        node *temp;
        printf("The deleted element is %d", front->data);
        temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        free(temp);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue Empty\n");
    }
    else
    {
        node *current = front;

        while (current != NULL)
        {
            printf("%d  ", current->data);
            current = current->next;
        }
    }
}