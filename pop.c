#include "monty.h"

/**
 * delete_node - deletes the node at head
 * @head: pointer to head
 * @index: index of the node to delete
 * Return: 1 in success, otherwise -1
 */

int delete_node(stack_t **head, unsigned int index)
{
	stack_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return (-1);
	if (current->prev != NULL)
		(current->prev)->next = current->next;
	if (current->next != NULL)
		(current->next)->prev = current->prev;
	if (current == *head && current->next != NULL)
		*head = current->next;
	if (current->next == NULL && current->prev == NULL)
		*head = NULL;
	free(current);
	return (1);
}
