#include <stdio.h>
#include <stdlib.h>

int top = -1;
int *arr;
int size;

void push()
{
    if(top == size-1)
    {
        printf("Stack is Full, cannot push data");
    }
    else
    {
        printf("Enter Data to Push: ");
        int data;
        scanf("%d", &data);
        arr[++top] = data;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow, cannot pop from EMPTY stack");
    }
    else
    {
        int data = arr[top--];
        printf("Popped Data : %d", data);
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack Underflow, cannot peek from EMPTY stack");
    }
    else
    {
        printf("Data at Position %d of STACK : %d", (top+1), arr[top]);
    }
}

int main()
{
    printf("Enter Maximum Stack Size : ");
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    char ch='y';
    while(ch=='y')
    {
        printf("Enter 1 To PUSH data\nEnter 2 to POP data\n");
        printf("Enter 3 To PEEK data\n");
        printf("Enter Choice: ... ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            default : printf("INVALID CHOICE");
        }
        printf("\nDo you want to continue...: \n");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }   
}