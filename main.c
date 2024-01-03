#include "monty.h"
cmddata_t cmddata = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int cont = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	cmddata.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((readline = getline(&content, &size, file)) != -1)
	{
	cmddata.content = content;
	cont++;
	execute(content, &stack, cont, file);
	free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
