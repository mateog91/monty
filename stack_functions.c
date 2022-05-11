#include "monty.h"

/**
 * add_node - add node at the start of stack
 * @head: pointer to first node
 * @n: integer in new node
 *
 * Return: pointer to new node
 */
stack_t *add_node(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	/* set new node's value */
	new->n = n;
	new->next = (*head);
	new->prev = NULL;

	/* Set previous first values "prev" to new node*/
	if (*head != NULL)
		(*head)->prev = new;

	/* Set head to first node */
	*head = new;
	return (new);
}

/**
 * swap - swaps 2 last nodes
 * @stack: stack
 * @line_number: line number
 * Return: 0
 */

int swap(stack_t **stack, unsigned int line_number)
{
	stack_t *second_node = NULL, *third_node = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		return (-1);
	}

	second_node = (*stack)->next;
	if (second_node->next != NULL)
	{
		third_node = second_node->next;
		third_node->prev = *stack;
	}
	second_node->prev = (*stack)->prev;
	second_node->next = (*stack);
	(*stack)->prev = second_node;
	if (third_node != NULL)
		(*stack)->next = third_node;
	else
		(*stack)->next = NULL;
	*stack = second_node;
	return (0);
}
