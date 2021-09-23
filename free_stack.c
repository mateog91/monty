#include "monty.h"

/**
  * free_stack - Frees the stack
  * @head: head pointer
  */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
