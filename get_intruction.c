#include "monty.h"
/**
 * get_instruction - finds the command
 *
 */

int (*get_instruction(char *command, unsigned int line_number,
		      char *current_line))(stack_t **, unsigned int)
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

int push(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	char *number;

	number = strtok(NULL, " \n");
	if (isdigit(number) != 0)
	{
		fprintf(stderr, "L%i: usage: push intege", line_number);
		return (-1);
	}

	printf("we are in push\n");
	return (0);
}
int pall(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	printf("we are in pall\n");
	return (0);
}
