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
	int n, i, flag = 0;

	if (cmd.arg)
	{
		if (cmd.arg[0] == '-')
			i++;
		for (i = 0; cmd.arg[i] != '\0'; i++)
		{
			if (cmd.arg[i] > 57 || cmd.arg[i] < 48)
				flag = 1; 
        }
		if (flag == 1)
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