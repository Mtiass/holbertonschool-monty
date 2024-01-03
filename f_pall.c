#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: array of structures. 
 * Return: no return
 */
void f_pall(stack_t **head)
{
	stack_t *h;

	h = *head;

	if (h == NULL)
		return;
    
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}