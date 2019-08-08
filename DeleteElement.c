void deleteFromBegin(LinkedList **head)                                            
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

void deleteFromEnd(LinkedList **head)                                               
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

void deleteFromIndex(LinkedList **head,int index)                           
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