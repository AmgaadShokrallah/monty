#include "monty.h"

/**
* func_pall - prints all the values on the stack
* @head: parameter1
* @line_num: parameter2
*
* Return: none
*/

void func_pall(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *head;
	if (tmp == NULL)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* f_swap - swaps the top two elements of the stack.
* @head: parameter1
* @line_num: parameter2
*
* Return: none
*/

void func_swap(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	int len = 0, temp;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(b.f);
		free(b.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	temp = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = temp;
}


/**
 * func_add -  adds the top two elements of the stack.
 * @head: parameter1
 * @line_num: parameter2
 *
 * Return: none
 */

void func_add(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;
	int len = 0, stack;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(b.f);
		free(b.cont);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	stack = tmp->n + tmp->next->n;
	tmp->next->n = stack;
	*head = tmp->next;
	free(tmp);
}

/**
 * func_push - pushes an element to the stack.
 * @head: parameter1
 * @line_num: parameter2
 *
 * Return: nothing
 */
void func_push(stack_t **head, unsigned int line_num)
{
	int i, j = 0, flg = 0;

	if (b.args)
	{
		if (b.args[0] == '-')
			j++;
		for (; b.args[j] != '\0'; j++)
		{
			if (b.args[j] > 57 || b.args[j] < 48)
				flg = 1; }
		if (flg == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(b.f);
			free(b.cont);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(b.f);
		free(b.cont);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(b.args);
	if (b.li == 0)
		add_node(head, i);
}
