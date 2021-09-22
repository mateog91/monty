#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	size_t line_number = 1;
	char *current_line = NULL;
	char *tokens[2];
	void (*func)(stack_t **, unsigned int);
	stack_t *head = NULL; /* declaring and initializing head */

	check_argc(argc);
	file = open_file(argv[1]);
	while (1)
	{
		current_line = get_current_line(current_line, file, line_number);
		tokens[0] = strtok(current_line, " \n"); /* check for other cases like tabs */
		if (tokens[0] == NULL)
		{
			line_number++;
			continue;
		}
		tokens[1] = strtok(NULL, " \n");
		/* get command */
		func = get_instruction(tokens[0], line_number, current_line);

		/* call the function*/
		func(&head, line_number);

		line_number++;
		free(current_line);
		current_line = NULL;
	}
	return (0);
}

char *get_current_line(char *current_line, FILE *file, size_t line_number)
{
	ssize_t line_len = 0;
	size_t size, i;

	line_len = getline(&current_line, &size, file);
	if (line_len == EOF)
	{
		printf("EOF reached, final line: %ld\n", line_number);
		free(current_line);
		exit(EXIT_SUCCESS);
	}
	for (i = 0; current_line[i] != '\n' && line_len > 0; i++)
		;
	current_line[i] = '\0';

	printf("line #%ld = %s\n", line_number, current_line);
	return (current_line);
}

void check_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

FILE *open_file(char *argv)
{
	FILE *file;

	file = fopen(argv, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open the file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	return (file);
}
