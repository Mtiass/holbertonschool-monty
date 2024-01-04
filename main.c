#include "monty.h"
/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char *argv[])
{
	cmd_t cmd = {NULL, NULL, NULL, 0};
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int cont = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	cmd.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		cmd.content = content;
		cont++;

		if (read_line > 0)
			execute(content, &stack, cont, file);

		free(content);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
