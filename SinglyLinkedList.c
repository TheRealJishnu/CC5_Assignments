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

void Delete_At_End()
{
    if(head == NULL)
    {
        printf("No Node to Delete");
    }
    else
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Delete_At_First()
{
    if(head == NULL)
    {
        printf("No Node to Delete");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void Insert_At_Index(int data, int index)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    node *ttm = head;

    for (int i = 0; i <= index-2; i++)
    {
        ttm = ttm->next;
    }
    temp->next = ttm->next;
    ttm->next = temp;
}

void Delete_At_Index(int index)
{
    node *ttm = head;
    for (int i = 0; i <= index-2; i++)
    {
        ttm = ttm->next;
    }
    node *temp = ttm->next;
    ttm->next = temp->next;
    free(temp);
}

int getLength() 
{
    node *temp = head;
    int count = 0;
    if (head == NULL) 
    {
        return 0;
    }
    else {
        while (temp != NULL) 
        {
            count++;
            temp = temp->next;
        }
    return ++count;
    }
}

int main()
{
    char ch='y';
    while(ch=='y')
    {
        printf("Enter 1 To Show Linked List\nEnter 2 to Enter Data at First\n");
        printf("Enter 3 To Add Data At The End\nEnter 4 to Enter Data At a Position\n");
        printf("Enter 5 To Delete First Node\nEnter 6 To Delete Last Node\n");
        printf("Enter 7 To Delete Node of a Position\nEnter 8 To Delete All Nodes\n");
        printf("Enter Choice: ... ");
        int choice;
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1 : Display(); break;
            case 2 : 
            {
                printf("Enter Data to be Added at First:    ");
                int data;
                scanf("%d", &data);
                Insert_At_Beginning(data);
                break;
            }
            case 3 : 
            {
                printf("Enter Data to be Added at End:    ");
                int data;
                scanf("%d", &data);
                Insert_At_End(data);
                break;
            }
            case 4 : 
            {
                printf("Enter Position to Add Data: ");
                int index;
                scanf("%d", &index);
                printf("Enter Data to be Added at %d:    ", index);
                int data;
                scanf("%d", &data);
                Insert_At_Index(data, index);
            }
            case 5 : Delete_At_First(); break;
            case 6 : Delete_At_End(); break;
            case 7 : 
            {
                printf("Enter Position to Delete: ");
                int index;
                scanf("%d", &index);
                Delete_At_Index(index); break;
            }
            case 8 :
            {
                int len = getLength();
                for (int i = 0; i < len; i++)
                {
                    Delete_At_First();
                }
                break;
            }
            default: printf("Enter Valid Input");
        }
        printf("\nDo you want to continue...: \n");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }
}
