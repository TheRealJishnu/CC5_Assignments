#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinkedList
{
    struct SingleLinkedList *next;
    int data;
} stackNode;

stackNode *head;
int max, current = -1;
int* arr;

void push(int data)
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
        return;
    }
    else
    {
        printf("Data at Position %d : %d", current+1, head->data);
    }

}

int main()
{
    printf("Enter Maximum Array Size : ");
    scanf("%d", &max);
    printf("Enter Data for the Aray: ");
    for (int i = 0; i < max; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original Array: ");
    for (int i = 0; i < max; i++) {
        scanf("%d\t", &arr[i]);
    }
}
