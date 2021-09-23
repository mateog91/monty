#include "monty.h"

/**
 * pint - the value at the top of the stack, followed by a new line.
 * @head: pointer to first node
 * @line_number: number of current line
 *
 * Return: 0 on succes, -1 on failure
 */
int pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty", line_number);
		return (-1);
	}

	printf("%i\n", (*head)->n);
	return (0);
}
