#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @cont: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int cont, cmd_t *cmd)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", cont);
		fclose(cmd.file);
		free(cmd.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}
