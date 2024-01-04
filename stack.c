#include "monty.h"

/**
 * free_stack - freedoubly linked list
 * @head: first node of stack
 * Return: none
 */

void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

/**
 * f_stack - free stack
 * @head: first node(unused)
 * @cont: line counter (unused)
 *
 * Return: none
*/

void f_stack(stack_t **head, unsigned int cont)
{
	(void)head;
	(void)cont;

	cmd.changer = 0;
}
