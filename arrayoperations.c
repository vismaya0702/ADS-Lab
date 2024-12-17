#include <stdio.h>
void insert(int num, int pos);
int delete(int pos);
void sort();
int search(int num);
void display();
int arr[40], size, flag = 1, op, num, pos, temp;
int main()
{
    printf("\nEnter size of the array:");
    scanf("%d", &size);
    printf("\nEnter the elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (flag == 1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Search\n4.Sort\n5.Display\n6.Exit\nChoose the array operation:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the element to be inserted:");
            scanf("%d", &num);
            printf("\nEnter the position:");
            scanf("%d", &pos);
            insert(num, pos);
            break;
        case 2:
            printf("\nEnter the Position of the element to be deleted:");
            scanf("%d", &pos);
            num = delete (pos);
            printf("\nDeleted Element=%d", num);
            break;
        case 3:
            printf("\nEnter the element to be searched:");
            scanf("%d", &num);
            int pos = search(num);
            if (pos == -1)
            {
                printf("\nElement not present");
            }
            else
            {
                printf("\nElement  present at position %d", pos);
            }
            break;
        case 4:
            sort();
            break;
        case 5:
            display();
            break;
        case 6:
            flag = 0;
            break;
        default:
            printf("\nEnter valid input");
        }
    }
}
void insert(int num, int pos)
{
    for (int i = size; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = num;
    size++;
    printf("\nInserted at position");
}
int delete(int pos)
{
    int val = arr[pos];
    size--;
    for (int i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return val;
}
void display()
{
    if (size <= 0)
    {
        printf("\nArray is empty\n");
    }
    else
    {
        printf("\nArray Elements\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}
void sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n Array Sorted\n");
}
int search(int num)
{
    int pos = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            pos = i;
            break;
        }
    }
    return pos;
}