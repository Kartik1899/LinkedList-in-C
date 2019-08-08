#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist {                                                 // Structure of linked list
    int value;                                 // to store value
    struct linkedlist *address;                // to store address of next element
} LinkedList;



void insertAtBegin(LinkedList **head)                                           // insert element at the beginning function()
{
    if(*head == NULL)
    {
        LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList));
        scanf("%d",&temp->value);
        temp->address = NULL;
        *head = temp;
    }
    else
    {
        LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList));
        scanf("%d",&temp->value);
        temp->address = *head;
        *head = temp;
    }
}

void insertAtIndex(LinkedList **head, int position)                                 // insert at a particular index function()
{
    if(position == 0)
    {
        insertAtBegin(head);
    }
    else
    {
        LinkedList *iterator = *head;
        while(position != 1)
        {
            iterator = iterator->address;
            position--;
        }

        LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList));
        scanf("%d",&temp->value);
        temp->address = iterator->address;

        iterator->address = temp;
    }
}


void insertAtEnd(LinkedList **head)                                                    // insert at the end of the list function()
{
     if( *head == NULL)
    {
        insertAtBegin(head);
    }

    else
    {
        LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList));
        scanf("%d",&temp->value);
        temp->address = NULL;
        
        LinkedList *iterator = *head;

        while( iterator->address != NULL)
        {
            iterator = iterator->address;
        }
        iterator->address = temp;        
    }
}

void deleteFromBegin(LinkedList **head)                                             // delete first element function()
{
    LinkedList *iterator = *head;
    if((*head)->address == NULL)
    {
        *head = NULL;
        free(iterator);
    }
    else
    {
        *head = (*head)->address;
        free(iterator);       
    }  
}

void deleteFromEnd(LinkedList **head)                                               // delete last element function()
{
    LinkedList *iterator = *head;
    if(iterator->address == NULL)
    {
        *head = NULL;
        free(iterator);
    }
    while(iterator->address != NULL && iterator->address->address != NULL)
    {
        iterator = iterator->address;
    }
    free(iterator->address);
    iterator->address = NULL;    
}

void deleteFromIndex(LinkedList **head,int index)                           // to delete an element at a particular index function()
{
    LinkedList *iterator = *head;
    if(index == 0)
    {
        deleteFromBegin(head);
    }
    else
    {
        while(index != 1)
        {
            iterator = iterator->address;
            index--;
        }
        LinkedList *temp;
        temp = iterator->address->address;
        free(iterator->address);
        iterator->address = temp;
    }

}
int findLength(LinkedList **head)                                              // function to find the length of list function()
{
    int count = 0;
    for(LinkedList *iterator = *head; iterator != NULL; iterator = iterator->address)
    {
        count++;
    }
    return count;
}

void print(LinkedList **head)                                                   // function to print list
{
    for(LinkedList *h = *head; h != NULL; h = h->address)
    {
        printf("%d ",h->value);
    }
}

int main()
{
    LinkedList *list1 = NULL;
    int i = 0;
    
    while(i < 5)                                                            // inserting elements at the start
    {
        insertAtBegin(&list1);
        i++;
    }

    int index;

    printf("Enter the index and value of element which you want to enter : ");
    scanf("%d",&index);

    int k =  findLength(&list1);
    if(k < index - 1 || index < 0)
    {
        printf("Invalid Index");
        exit(0);
    }

    insertAtIndex(&list1,index);                                                // inserting elements at a particular address

    print(&list1);
    printf("\n");

    deleteFromIndex(&list1,index);                                              // deleting element at a particular address
    
    print(&list1);

    return 0;
}