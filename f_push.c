#include "monty.h"
/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @counter: line count
 *
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int cont)
{
	int n, i  = 0, flag = 0;

	if (cmddata.arg)
	{
		if (cmddata.arg[0] == '-')
			i++;
		for (; cmddata.arg[i] != '\0'; i++)
		{
			if (cmddata.arg[i] > 57 || cmddata.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", cont);
			fclose(cmddata.file);
			free(cmddata.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", cont);
		fclose(cmddata.file);
		free(cmddata.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(cmddata.arg);
	if (cmddata.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
