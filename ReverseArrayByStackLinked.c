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
        //printf("Enter Data to Add in Stack :  ");
        //scanf("%d", &data);
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
        return;
        //printf("Stack is Full, cannot push data");
    }
 
}

int pop()
{
    if(head == NULL)
    {
        return;
        //printf("Stack is Empty, No data to POP");
    }
    else if(head->next == NULL)
    {
        int ret = head->data;
        free(head);
        head = NULL;
        return ret;
    }
    else
    {
        int ret = head->data;
        //printf("Popped Data : %d", head->data);
        stackNode *temp = head;
        head = head->next;
        free(temp);
        return ret;
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
    printf("Enter Maximum Array Size : ");          //Array Input
    scanf("%d", &max);
    int *arr = (int*)malloc(max * sizeof(int));
    printf("Enter Data for the Aray: ");
    for (int i = 0; i < max; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original Array: ");
    for (int i = 0; i < max; i++) {
        printf("%d\t", arr[i]);
    }
    
    for (int i = 0; i < max; i++) {
        push(arr[i]);
    }
    for (int i = 0; i < max; i++) {
        arr[i] = pop();
    }
    printf("Reversed Array: ");
    for (int i = 0; i < max; i++) {
        printf("%d\t", arr[i]);
    }
    
    
}
