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

/**
 * add - add top 2 numbers of stack
 * @head: pointer to first node
 * @line_number: number of current line
 * Description:
 * The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 *
 * Return: 0 on succes, -1 on failure
 */
int add(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int sum;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		return (-1);
	}

	sum = current->n + current->next->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n = sum;
	free(current);
	return (0);
	printf("after return");
}
