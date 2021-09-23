#include "monty.h"

int swap(stack_t **stack, unsigned int line_number)
{
	stack_t *second_node, *third_node;

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
	(*stack)->next = third_node;
	*stack = second_node;
	return (0);
}
