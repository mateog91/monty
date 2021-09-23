#include "monty.h"

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
