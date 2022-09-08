#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top element
 * by the top element
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_num)
{
	int modulo;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_MOD);
	if ((*stack)->n == 0)
		handle_errors(ERROR_DIV_ZERO);
	modulo = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_num);
	(*stack)->n = modulo;
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_num)
{
	(void)line_num;

	if (!stack || !*stack)
		handle_errors(ERROR_STACK_EMPTY);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		handle_errors(ERROR_PCHAR_RANGE);
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	for (tmp = *stack; tmp; tmp = tmp->next)
	{
		if (tmp->n < 1 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
	}
	putchar('\n');
}

/**
 * _rotl - rotates the stack to the top
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_num)
{
	int last;
	stack_t *tmp;
	(void)line_num;

	if (stack && *stack)
	{
		last = (*stack)->n;
		for (tmp = *stack; tmp->next; tmp = tmp->next)
			tmp->n = tmp->next->n;
		tmp->n = last;
	}
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_num)
{
	int nxt, curr;
	stack_t *tmp;
	(void)line_num;

	if (stack && *stack)
	{
		tmp = *stack;
		nxt = tmp->n;
		while (tmp->next)
		{
			curr = nxt;
			nxt = tmp->next->n;
			tmp->next->n = curr;
			tmp = tmp->next;
		}
		(*stack)->n = nxt;
	}
}
