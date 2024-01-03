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
	
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

    aux = *head;
    
    if (aux)
        aux->prev = newnode;

    newnode->n = n;
	newnode->next = *head;
    newnode->prev = NULL;
	*head = newnode;
}