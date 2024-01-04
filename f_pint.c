#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @cont: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int cont)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cont);
		fclose(cmd.file);
		free(cmd.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}