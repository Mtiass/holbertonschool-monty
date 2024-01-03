#include "monty.h"
#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @cont: line_counter
* @file: pointer to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int cont, FILE *file)
{
    char *op;
    unsigned int i;
    
	instruction_t opst[] = 
    {
				{"push", f_push},
                {"pall", f_pall},
				{NULL, NULL}
    };

	i = 0;
    op = strtok(content, " \n\t");
	cmddata.arg = strtok(NULL, " \n\t");
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