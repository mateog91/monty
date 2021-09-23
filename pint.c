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
	int opp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		return (-1);
	}

	opp = current->n + current->next->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n = opp;
	free(current);
	return (0);
}

/**
 * sub - sub top 2 numbers of stack
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
int sub(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int opp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		return (-1);
	}

	opp = current->next->n - current->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n = opp;
	free(current);
	return (0);
}

/**
 * div - divides top 2 numbers of stack
 * @head: pointer to first node
 * @line_number: number of current line
 * Description:
 * The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 * if second is 0, it fails
 *
 * Return: 0 on succes, -1 on failure
 */
int divi(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int opp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		return (-1);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%i: division by zero", line_number);
		return (-1);
	}
	opp = current->n / current->next->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n = opp;
	free(current);
	return (0);
}

/**
 * nop - does nothing
 * @head: pointer to first node
 * @line_number: number of current line

 * Return: always 0
 */
int nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	return (0);
}