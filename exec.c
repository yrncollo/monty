#include "monty.h"

/**
 * handle_opcode - handles opcode and matches with their paired functions
 *
 * Return: function
 */
void (*handle_opcode(void))(stack_t **stack, unsigned int line_num)
{
	char *input_opcode;
	instruction_t *i;
	static instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", _nop},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	i = instructions;
	input_opcode = inventory->input[0];
	while (i->opcode && strncmp(i->opcode, input_opcode, strlen(input_opcode)))
		i++;
	if (!i->f)
		handle_errors(ERROR_UKNOWN);
	return (i->f);
}

/**
 * parse_l - parses line into input global variable
 * @line: input line
 * Return: exit status
 */
int parse_l(char *line)
{
	char *delimiter, *str;
	int len, i;

	delimiter = "\n ";
	str = inventory->line;
	len = strlen(str);
	for (i = 0; str[i] == delimiter[0] || str[i] == delimiter[1]; i++)
		;
	if (i == len)
		return (EXIT_FAILURE);
	inventory->input[0] = strtok(line, delimiter);
	if (inventory->input[0][0] == '#')
		return (EXIT_FAILURE);
	inventory->input[1] = strtok(NULL, delimiter);
	return (EXIT_SUCCESS);
}
