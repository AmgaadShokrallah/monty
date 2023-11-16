#include "monty.h"
#define _GNU_SOURCE

strc_t b = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: parameter1
* @argv: parameter2
*
* Return: always 0
*/
int main(int argc, char **argv)
{
	char *c;
	FILE *f;
	size_t size = 0;
	ssize_t line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");
	b.f = f;

	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line > 0)
	{
		c = NULL;
		line = getline(&c, &size, f);
		b.cont = c;
		count++;

		if (line > 0)
			execute(c, &stack, count, f);

		free(c);
	}

	free_stack(stack);
	fclose(f);
	return (0);
}
