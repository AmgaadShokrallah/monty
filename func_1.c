#include "monty.h"

/**
 * func_pop -  removes the top element of the stack.
 * @head: parameter1
 * @line_num: parameter2
 *
 * Return: none
 */

void func_pop(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(b.f);
		free(b.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = tmp->next;
	free(tmp);
}

/**
 * func_print - prints the value at the top of the stack
 * @head: parameter1
 * @line_num: parameter2
 *
 * Return: none
 */

void func_print(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(b.f);
		free(b.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * func_nop - doesn’t do anything
 * @head: parameter1
 * @line_num: parameter2
 *
 * Return: none
 */

void func_nop(stack_t **head, unsigned int line_num)
{
	(void) line_num;
	(void) head;
}

/**
* addnode - add node to stack
* @head: parameter1
* @n: parameter2
*
* Return: none
*/

void add_node(stack_t **head, int n)
{
	stack_t *node_n, *tmp;

	tmp = *head;
	node_n = malloc(sizeof(stack_t));

	if (node_n == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = node_n;

	node_n->n = n;
	node_n->next = *head;
	node_n->prev = NULL;
	*head = node_n;
}
