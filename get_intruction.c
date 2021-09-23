#include "monty.h"
/**
 * get_inst - finds the command
 * @command: command
 * @line_number: line number
 * Return: pointer to function
 */

int (*get_inst(char *command, unsigned int line_number))()
{
	int i;

	instruction_t array_instructions[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pop", pop},
	    {"pint", pint},
	    {"swap", swap},
	    {"add", add},
	    {"nop", nop},
	    {"sub", sub},
	    {NULL, NULL}};

	for (i = 0; array_instructions[i].opcode != NULL; i++)
	{
		if (strcmp(command, array_instructions[i].opcode) == 0)
			return (array_instructions[i].f);
	}
	/* if not found then error message and exit*/
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, command);
	return (NULL);
}

/**
  * push - push a node to the stack
  * @stack: head pointer to the stack
  * @line_number: the number of the current line
  * Return: 0 if success, -1 if an error ocurred
  */

int push(stack_t **stack, unsigned int line_number)
{
	char *number;
	int i;
	int real_number;

	number = strtok(NULL, " \n");
	if (number == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		return (-1);
	}
	for (i = 0; number[i] != '\0'; i++)
	{
		if (number[i] == '-' && i == 0)
			continue;
		if (isdigit(number[i]) == 0)
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_number);
			return (-1);
		}
	}

	real_number = atoi(number);

	/* ADD THE NEW NODE */
	add_node(stack, real_number);

	return (0);
}

/**
  * pall - prints all the stack
  * @stack: head pointer to srack
  * @line_number: number of the current line
  * Return: 0 if success, -1 if an error ocurred
  */

int pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	if ((*stack) == NULL)
		return (0);
	current = (*stack);
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	return (0);
}

/**
  * pop - deletes the node at top of the stack
  * @stack: header pointer to stack
  * @line_number: number of the line
  * Return: 0 success, otherwise -1
  */

int pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		return (-1);
	}
	delete_node(stack, 0);
	return (0);
}
