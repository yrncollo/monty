#include "monty.h"
#include <stdio.h>

/**
 * main - main function of the program
 * @argc: number of arguments
 * @argv: argument vector
 * Return: 0 always
 */
int main(int argc, char **argv)
{
	size_t n;
	void (*execute)(stack_t **stack, unsigned int line_num);

	inventory = NULL;
	if (argc != 2)
		handle_errors(ERROR_USAGE_FILE);
	inventory_structure();
	inventory->filename = argv[1];
	inventory->file = fopen(inventory->filename, "r");
	if (inventory->file == NULL)
		handle_errors(ERROR_OPEN_FILE);
	while (getline(&inventory->line, &n, inventory->file) > 0)
	{
		inventory->line_num++;
		if (parse_l(inventory->line) == EXIT_FAILURE)
			continue;
		execute = handle_opcode();
		execute(&inventory->stack, inventory->line_num);
	}
	free_all();
	return (EXIT_SUCCESS);
}
