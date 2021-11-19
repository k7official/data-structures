#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main()
{
    node *list = NULL; // creating an empty linked list

    node *n = malloc(sizeof(node));
    if(n != NULL)
    {
        n->number = 1;
        n->next = NULL; //make sure the pointer to the next node in our list isn't a garbage value
    }
    list = n; //our list need to point to this node

    n = malloc(sizeof(node));
    if(n != NULL)
    {
        n->number = 2;
        n->next = NULL;
    }
    list->next = n; //update the pointer in our first node to point to our new n

    //To add a third node, we’ll do the same by following the next pointer in our list first, 
    //then setting the next pointer there to point to the new node
    n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = 3;
        n->next = NULL;
    }
    list->next->next = n;

    //displaying the linked list
    for(node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("%d\n", temp->number);
    }

    //linked list insertion
    n = malloc(sizeof(node));
    if(n != NULL)
    {
        n->number = 0;
        n->next = NULL;
    }
    n->next = list;
    list = n;

    for(node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("%d\n", temp->number);
    }

    n = malloc(sizeof(node));
    if(n != NULL)
    {
        n->number = 5;
        n->next = NULL;
    }
    n->next = list->next->next->next;
    list->next->next->next = n;
    for(node *temp = list; temp != NULL; temp = temp->next)
    {
        printf("%d\n", temp->number);
    }

    //free list using while loop and temporary variable to point to next next node before
    //freeing  the current one
    while (list != NULL)
    {
        node *temp = list->next;//point to the next node first
        free(list); //free the first node 
        list = temp;//set list to point to the next node
    }
    
    

    return 0;
}

