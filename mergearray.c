#include<stdio.h>


void main(){

    int n, m;
    printf("Enter the size of first array: ");
    scanf("%d", &n);
    printf("Enter the size of second array: ");
    scanf("%d", &m);

    int a[n], b[m], c[m + n];

    printf("\nEnter the elements of first array: \n");
    for(int i = 0; i<n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("\nEnter the elements of second array: \n");
    for(int i = 0; i<m; i++){
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }
  
    for(int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }

    for(int i = n; i < m + n; i++)
    {
        c[i] = b[i - n];
    }

    printf("\nThe merged array is: ");
    for(int i=0; i < m + n; i++){
        printf("%d ", c[i]);
    }
}
