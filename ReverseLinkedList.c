#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinkedList
{
    struct SingleLinkedList *next;
    int data;
} node;
node *head;

void Insert_At_End(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;

    if (head == NULL)
    {
        head = temp;
    }

    else
    {
        node *ttm = head;
        while (ttm->next != NULL)
        {
            ttm = ttm->next;
        }

        ttm->next = temp;
    }
}

void Insert_At_Beginning(int data)
{
    node *temp = (node*)malloc(sizeof(node));
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
}

void Display()
{
    if(head==NULL)
    {
        printf("Linked List is Empty");
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        return;
    }
    
}

void Reverse(node *current,node *prevCurrent)
{
   if(!head) return; 
   else if(current->next==NULL)
   {
       head = current;
       current->next = prevCurrent;
       return;
   }
   node *nextCurrent = current->next;

   current->next = prevCurrent;

   Reverse(nextCurrent, current);
}

int main()
{
    Insert_At_Beginning(10);
    Insert_At_Beginning(20);
    Insert_At_Beginning(30);
    Insert_At_Beginning(40);
    Insert_At_Beginning(50);
    Display();
    printf("\n");
    Reverse(head, NULL);
    Display();
}

