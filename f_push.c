#include "monty.h"
/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @cont: line counter
 *
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int cont)
{
	int n, i, notnum = 0;

	i = 0;
	if (cmd.arg)
	{
		if (cmd.arg[0] == '-')
			i++;
		for (; cmd.arg[i] != '\0'; i++)
		{
			if (cmd.arg[i] > 57 || cmd.arg[i] < 48)
				notnum = 1; 
			}
		if (notnum == 1)
		{ 
			fprintf(stderr, "L%d: usage: push integer\n", cont);
			fclose(cmd.file);
			free(cmd.content);
			free_stack(*head);
			exit(EXIT_FAILURE); 
			}
		}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n", cont);
		fclose(cmd.file);
		free(cmd.content);
		free_stack(*head);
		exit(EXIT_FAILURE); 
		}
	n = atoi(cmd.arg);
	if (cmd.changer == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
