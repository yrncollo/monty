#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_ADD);
	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_num);
	(*stack)->n = sum;
}

/**
 * _nop - does nothing
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_num)
{
	int diff;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_SUB);
	diff = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_num);
	(*stack)->n = diff;
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_num)
{
	int quotient;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_DIV);
	if ((*stack)->n == 0)
		handle_errors(ERROR_DIV_ZERO);
	quotient = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_num);
	(*stack)->n = quotient;
}

/**
 * _mul - multiplies the second top element of the stack with the top element
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_num)
{
	int product;

	if (*stack == NULL || (*stack)->next == NULL)
		handle_errors(ERROR_MUL);
	product = (*stack)->next->n * (*stack)->n;
	_pop(stack, line_num);
	(*stack)->n = product;
}
