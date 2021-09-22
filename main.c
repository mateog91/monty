#include "monty.h"

/**
  * main - main function for monty interpreter
  * @argc: number of arguments
  * @argv: arguments
  * Return: always 0
  */

int main(int argc, char **argv)
{
	FILE *file;
	size_t line_number = 1;
	char *current_line = NULL;
	char *command;
	int (*func)(stack_t **, unsigned int);
	stack_t *head = NULL; /* declaring and initializing head */
	int error_check = 0;

	check_argc(argc);
	file = open_file(argv[1]);
	while (1)
	{
		current_line = get_current_line(current_line, file);

		/*
		printf("line #%ld: %s\n", line_number, current_line);*/

		command = strtok(current_line, " \n"); /* check for other cases like tabs */
		if (command == NULL)
		{
			line_number++;
			continue;
		}

		/* get command */
		func = get_inst(command, line_number, current_line);

		/* call the function*/
		error_check = func(&head, line_number);
		if (error_check == -1)
			_oexit(current_line, file);

		line_number++;
		free(current_line);
		current_line = NULL;
	}
	return (0);
}

/**
  * get_current_line - gets the current line
  * @current_line: pointer to the current line
  * @file: pointer to the file
  * Return: pointer to the current line
  */

char *get_current_line(char *current_line, FILE *file)
{
	ssize_t line_len = 0;
	size_t size, i;

	line_len = getline(&current_line, &size, file);
	if (line_len == EOF)
	{
		free(current_line);
		exit(EXIT_SUCCESS);
	}
	for (i = 0; current_line[i] != '\n' && line_len > 0; i++)
		;
	current_line[i] = '\0';
	return (current_line);
}

/**
  * check_argc - checks if there is 2 arguments
  * @argc: number of arguments
  */

void check_argc(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
  * open_file - open the file
  * @argv: arguments
  * Return: file pointer
  */

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

/**
  * _oexit - exits the file and frees the line
  * @current_line: current line
  * @file: file pointer
  */

void _oexit(char *current_line, FILE *file)
{
	free(current_line);
	fclose(file);
	exit(EXIT_FAILURE);
}
