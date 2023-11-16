#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct strc_s - variables -args, f, li, -cont
 * @args: parameter1
 * @f: parameter2
 * @cont: parameter3
 * @li: parameter4
 *
 * Description: carries values through the program
 */
typedef struct strc_s
{
	char *args;
	FILE *f;
	char *cont;
	int li;
}  strc_t;
extern strc_t b;

void free_stack(stack_t *head);
void func_push(stack_t **head, unsigned int number);
void func_pall(stack_t **head, unsigned int number);
void func_print(stack_t **head, unsigned int number);
void func_pop(stack_t **head, unsigned int line_num);
void func_swap(stack_t **head, unsigned int line_num);
void func_nop(stack_t **head, unsigned int line_num);
void func_add(stack_t **head, unsigned int line_num);
void add_node(stack_t **head, int n);
void f_stack(stack_t **head, unsigned int line_num);

ssize_t getline(char **lpt, size_t *n, FILE *strm);
int execute(char *cont, stack_t **head, unsigned int counter, FILE *f);

#endif
