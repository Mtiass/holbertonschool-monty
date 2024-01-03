#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @i: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{
	stack_t *aux, *newnode = malloc(sizeof(stack_t));

    aux = *head;
	if (newnode == NULL)
	{
		free(newnode);
		return (NULL); 
    }
    
    if (aux)
        aux->prev = newnode;

    newnode->n = n;
	newnode->next = *head;
    newnode->prev = NULL;
	*head = newnode;
}