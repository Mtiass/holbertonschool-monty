#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number)
{
    int i;
    char *arg = strtok(NULL, " \n\t");

    if (arg == NULL || check_if_number(arg) == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int n = atoi(arg);
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
