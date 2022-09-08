#include "monty.h"

/**
 * are_digits - checks if characters in a string are digits
 * @str - string to be checked
 * Return: 0 or 1
 */
int are_digits(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-' && i == 0)
			i++;
		if (isdigit(str[i]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}
