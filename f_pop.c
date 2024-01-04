#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @cont: line_number
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int cont, cmd_t *cmd)
{
	stack_t *aux;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", cont);
		fclose(cmd.file);
		free(cmd.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	*head = aux->next;
	free(aux);
}
