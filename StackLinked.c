#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinkedList
{
    struct SingleLinkedList *next;
    int data;
} stackNode;

stackNode *head;
int max, current = -1;

void push()
{
    if(current < max-1)
    {
        stackNode *temp = (stackNode*)malloc(sizeof(stackNode));
        int data;
        printf("Enter Data to Add in Stack :  ");
        scanf("%d", &data);
        temp->data = data;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        current = current + 1;
    }
    else
    {
        printf("Stack is Full, cannot push data");
    }
    printf("current %d", current);
}

void pop()
{
    if(head == NULL)
    {
        printf("Stack is Empty, No data to POP");
    }
    else if(head->next == NULL)
    {
        printf("Popped Data : %d", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        printf("Popped Data : %d", head->data);
        stackNode *temp = head;
        head = head->next;
        free(temp);
    }
    current--;
}

void peek()
{
    if(head == NULL)
    {
        printf("Stack is Empty, No data to Show");
    }
    else
    {
        printf("Data at Position %d : %d", current+1, head->data);
    }

}

int main()
{
    printf("Enter Maximum Stack Size : ");
    scanf("%d", &max);
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