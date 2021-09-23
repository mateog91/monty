#include "monty.h"

/**
 * mul - mul top 2 numbers of stack
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
int mul(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int opp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		return (-1);
	}

	opp = current->n * current->next->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n = opp;
	free(current);
	return (0);
}

/**
 * modu - mode top 2 numbers of stack
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
int modu(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int opp;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		return (-1);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%i: division by zero", line_number);
		return (-1);
	}
	opp = current->next->n % current->n;
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	(*head)->n = opp;
	free(current);
	return (0);
}
