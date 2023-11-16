#include "monty.h"

/**
* execute - func to execute opcode
* @stack: parameter1
* @counter: parameter2
* @f: parameter3
* @cont: parameter4
*
* Return: none
*/
int execute(char *cont, stack_t **stack, unsigned int counter, FILE *f)
{
	instruction_t opst[] = {
				{"push", func_push},
				{"pall", func_pall},
				{"pint", func_print},
				{"pop", func_pop},
				{"swap", func_swap},
				{"add", func_add},
				{"nop", func_nop},
				{NULL, NULL}
	};
	unsigned int i = 0;
	char *p;

	p = strtok(cont, " \n\t");
	if (p && p[0] == '#')
		return (0);
	b.args = strtok(NULL, " \n\t");
	while (opst[i].opcode && p)
	{
		if (strcmp(p, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (p && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, p);
		fclose(f);
		free(cont);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
