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
	printf("head number is: %i\n", (*head)->n);

	return (new);
}
