void insertAtBegin(LinkedList **head)
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


void insertAtEnd(LinkedList **head)
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

        while(iterator->address != NULL)
        {
            iterator = iterator->address;
        }
        iterator->address = temp;
    }
}


void insertAtIndex(LinkedList **head, int index)
{
    if(index == 0)
    {
        insertAtBegin(head);
    }
    else
    {
        LinkedList *iterator = *head;
        while( index != 1)
        {
            iterator = iterator->address;
            index--;
        }

        LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList));
        scanf("%d",&temp->value);
        temp->address = iterator->address;

        iterator->address = temp;
    }
}