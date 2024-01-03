#include "monty.h"

void read_file(char *filename)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        cmddata.content = line;
        if (execute(line, &stack, line_number, file) == EXIT_FAILURE)
        {
            free(line);
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    read_file(argv[1]);

    return (EXIT_SUCCESS);
}
