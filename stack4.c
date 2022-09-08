#include "monty.h"

/**
 * _stack - sets data format to LIFO in a stack
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _stack(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;

	inventory->order = LIFO;
}

/**
 * _queue - sets data format to FIFO in a stack
 * @stack: the stack
 * @line_num: line number
 * Return: void
 */
void _queue(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;

	inventory->order = FIFO;
}
