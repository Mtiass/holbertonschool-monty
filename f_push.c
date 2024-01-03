#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: array of structures
 * @cont: current line counter
 * Return: no return
 */
void f_push(stack_t **head, unsigned int cont)
{
    int n, i, notdigit = 0;
    
    if (cmddata.arg)
    {
        if (cmddata.arg[0] == '-')
            i++;

        for (i = 0; cmddata.arg[0] != '\0'; i++)
        {
            if (cmddata.arg[i] > '9' || cmddata.arg[i] < '0')
            notdigit = 1;
        }
        if (notdigit == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", cont);
			fclose(cmddata.file);
			free(cmddata.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(cmddata.file);
		free(cmddata.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
    }
    n = atoi(cmddata.arg);

    if (cmddata.stackqueue_flag = 0)
        addnode(head,n);
    else
        addqueue(head,n);
}
