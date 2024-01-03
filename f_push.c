#include "monty.h"
int is_valid_number(const char *str)
{
    int i = 0;

    if (str == NULL || str[0] == '\0')
        return 0;

    if (str[0] == '-')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1;
}

void f_push(stack_t **head, unsigned int cont)
{
    int n;

    if (!cmd.arg || !is_valid_number(cmd.arg))
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
