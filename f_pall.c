#include "monty.h"

void f_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int check_if_number(char *str)
{
    int i = 0;

    if (str[i] == '-')
    {
        i++;
    }

    for (; str[i]; i++)
    {
        if (isdigit(str[i]) == 0)
        {
            return (0);
        }
    }

    return (1);
}