#include "monty.h"

/**
 * add_node_order_LIFO - adds new node to the beginning of the stack
 * @stack: head of the stack
 * @new: node to be added
 * Return: void
 */
void add_node_order_LIFO(stack_t **stack, stack_t *new)
{
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * add_node_order_FIFO - adds new node at the end of the stack
 * @stack: head of the stack
 * @new: node to be added
 * Return: void
 */
void add_node_order_FIFO(stack_t **stack, stack_t *new)
{
	stack_t *tmp = *stack;

	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

/**
 * _push - adds new node to the stack
 * @stack: head of the stack
 * @line_num: line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_num)
{
	stack_t *new = NULL;
	char *nm;
	(void)line_num;

	if (inventory->input[1] == NULL)
		handle_errors(ERROR_PUSH);
	else
		nm = inventory->input[1];
	if (are_digits(nm) == TRUE)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
			handle_errors(ERROR_MALLOC);
	}
	else
		handle_errors(ERROR_PUSH);
	new->n = atoi(nm);
	if (inventory->order == LIFO)
		add_node_order_LIFO(stack, new);
	else
		add_node_order_FIFO(stack, new);
}
