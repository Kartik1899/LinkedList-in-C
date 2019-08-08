void print(LinkedList **head)
{
    for(LinkedList *h = *head; h != NULL; h = h->next)
    {
        printf("%d ",h->value);
    }
}