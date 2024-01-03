#include "monty.h"

/**
* execute - execute opcode
* @stack: stack of linked list
* @cont: line counter
* @file: pointer to monty file stream
* @content: line content
*
* Return: none
*/
int execute(char *content, stack_t **stack, unsigned int cont, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push},
                {"pall", f_pall},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	cmd.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	
            opst[i].f(stack, cont);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ 
        fprintf(stderr, "L%d: unknown instruction %s\n", cont, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
    }
	return (1);
}