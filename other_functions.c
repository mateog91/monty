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
	if (number >= 32 && number <= 126)
		printf("%c\n", number);
	else
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		return (-1);
	}
	return (0);
}

/**
 * pstr  -  prints the string starting at the top of the stack, followed by a
 * new line.
 * @head: pointer to first node
 * @line_number: number of current line
 *
 * Description:
 * The integer stored in each element of the stack is treated as the ascii value of the character to be printed
 * The string stops when either:
 * the stack is over
 * the value of the element is 0
 * the value of the element is not in the ascii table
 *
 * Return: 0 on succes, -1 on failure
 */
int pstr(stack_t **head, unsigned int line_number)
{
	int number;
	stack_t *current = *head;

	if (*head == NULL)
	{
		printf("\n");
		return (0);
	}

	while (current != NULL)
	{
		number = current->n;
		if (number < 32 || number > 126 || number == 0)
			break;

		printf("%c");
		current = current->next;
	}
	printf("\n");
	return (0);
}
