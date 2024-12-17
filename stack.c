#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top;

void push(int value);
int pop();
void display();

int main()
{
    int num;
    struct node *top ;

    printf("\n----STACK USING LINKED LIST----\n\n");

    int choice;

    while (choice != 4)
    {
        printf("\n Operations \n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n\n Select an operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            if(top == NULL)
            {
                printf("Stack is empty!");
            }
            else
            {
                num = pop();
                printf("The popped element is: %d", num);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        
        default:
            break;
        }
    }
}

void push(int value)
{
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node*));

    if(newNode == NULL)
    {
        printf("Memory overflow!");
    }
    else
    {
        newNode->data = value;
        newNode->next = NULL;

        if(top == NULL)
        {
            top = newNode;
        }
        else 
        {
            printf("hai");
            newNode->next = top;
            top = newNode;
        }
    }
}

int pop()
{
    struct node* deleteNode;
    int element;

    deleteNode = top;
    element = deleteNode->data;
    top = top->next;
    free(deleteNode);

    return element;
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty!");
    }
    else 
    {
        struct node *current;
        current = top;

        while (current != NULL)
        {
            printf("%d  ", current->data);
            current = current->next;
        }
    }
}