#include "monty.h"

/**
 * handle_errors - handles specific types of errors
 * @e: index of the error on the errors array
 * Return: void
 */
void handle_errors(int e)
{
	unsigned int line;
	static char *const errors[] = {
		"Error: malloc failed\n",
		"USAGE: monty file\n",
		NULL,
		NULL,
		"usage: push integer\n",
		"can't pint, stack empty\n",
		"can't pop an empty stack\n",
		"can't swap, stack too short\n",
		"can't add, stack too short\n",
		"can't sub, stack too short\n",
		"can't div, stack too short\n",
		"division by zero\n",
		"can't mul, stack too short\n",
		"can't mod, stack too short\n",
		"can't pchar, stack empty\n",
		"can't pchar, value out of range\n",
	};

	if (inventory)
		line = inventory->line_num;
	if (e <= 1)
		dprintf(STDOUT_FILENO, "%s", errors[e]);
	else if (e == 2)
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", inventory->filename);
	else if (e == 3)
		dprintf(STDOUT_FILENO, "L%u: unknown instruction %s\n", line,
		 inventory->input[0]);
	else if (e >= 4)
		dprintf(STDOUT_FILENO, "L%u: %s", line, errors[e]);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * free_stack - frees all malloc in stack
 *
 * Return: void
 */
void free_stack(void)
{
	stack_t *tmp, *head;

	if (inventory->stack)
	{
		head = inventory->stack;
		while (head)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
	}
}

/**
 * free_all - frees all malloc memory
 *
 * Return: void
 */
void free_all(void)
{
	if (inventory != NULL)
	{
		if (inventory->file != NULL)
			fclose(inventory->file);
		if (inventory->line != NULL)
			free(inventory->line);
		if (inventory->input != NULL)
			free(inventory->input);
		free_stack();
		free(inventory);
	}
}
