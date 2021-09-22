#include "monty.h"
/**
 * get_inst - finds the command
 * @command: command
 * @line_number: line number
 * @current_line: the current line
 * Return: pointer to function
 */

int (*get_inst(char *command, unsigned int line_number, char *current_line))()
{
	int i;

	instruction_t array_instructions[] = {
	    {"push", push},
	    {"pall", pall},
	    {NULL, NULL}};

	for (i = 0; array_instructions[i].opcode != NULL; i++)
	{
		if (strcmp(command, array_instructions[i].opcode) == 0)
			return (array_instructions[i].f);
	}
	/* if not found then error message and exit*/
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, command);
	free(current_line);
	exit(EXIT_FAILURE);
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

	for (i = 0; number[i] != '\0'; i++)
	{
		if (isdigit(number[i]) == 0 && number[0] != '-')
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_number);
			return (-1);
		}
	}

	real_number = atoi(number);
	printf("real number is: %i\n", real_number);

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
