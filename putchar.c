#include "monty.h"

/**
 * pchar -  prints the char at the top of the stack, followed by a new line.
 * @head: pointer to first node
 * @line_number: number of current line
 *
 * Description:
 * The integer stored at the top of the stack is treated as the ascii
 * value of the character to be printed
 *
 * Return: 0 on succes, -1 on failure
 */
int pchar(stack_t **head, unsigned int line_number)
{
	int number;

	if (*head == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		return (-1);
	}
	number = (*head)->n;
	if (number >= 0 && number <= 255)
		printf("%c\n", number);
	else
	{
		fprintf(stderr, "L%i: can't pchar, value out of range", line_number);
		return (-1);
	}
	return (0);
}
