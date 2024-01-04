#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @cont: line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int cont)
{
	stack_t *temp;

	int len = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", cont);
		fclose(cmd.file);
		free(cmd.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n + temp->next->n;
	temp->next->n = aux;
	*head = temp->next;
	free(temp);
}