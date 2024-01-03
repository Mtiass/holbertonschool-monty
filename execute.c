#include "monty.h"

cmd_t cmd = {NULL, NULL, NULL, 0};

void execute(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
    char *token;
    int value;

    token = strtok(content, " \t\n");
    if (!token || token[0] == '#')
        return;

    cmd.arg = strtok(NULL, " \t\n");

    if (strcmp(token, "push") == 0)
    {
        if (!cmd.arg || !is_numeric(cmd.arg))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(cmd.file);
            free(cmd.content);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
        value = atoi(cmd.arg);
        push(stack, value);
    }
    else if (strcmp(token, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
}