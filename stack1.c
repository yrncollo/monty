#include "monty.h"

/**
 * _pall - prints all the values on the stack
 * @stack: head of stack
 * @line_num: line number
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *cpy;
	(void)line_num;

	for (cpy = *stack; cpy; cpy = cpy->next)
		printf("%d\n", cpy->n);
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: head of stack
 * @line_num: line number
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	(void)line_num;

	if (!stack || !*stack)
		handle_errors(ERROR_PINT);
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: head of stack
 * @line_num: line number
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *nxt;
	(void)line_num;

	if (*stack == NULL)
		handle_errors(ERROR_POP);
	else if ((*stack)->next != NULL)
	{
		nxt = (*stack)->next;
		nxt->prev = NULL;
		free(*stack);
		*stack = nxt;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: head of stack
 * @line_num: line number
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	int tmp;
	(void)line_num;

	if (!stack || !*stack || !(*stack)->next)
		handle_errors(ERROR_SWAP);
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
