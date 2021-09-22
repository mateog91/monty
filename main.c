#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	ssize_t line_len = 0;
	size_t size, line_number = 0;
	char *current_line = NULL;

	check_argc(argc);
	file = open_file(argv[1]);
	printf("File was opened\n");
	while (line_len != EOF)
	{
		line_len = getline(&current_line, &size, file);
		printf("line #%ld = %s", line_number, current_line);
		line_number++;
	}
	printf("EOF reached, final line: %ld\n", line_number);
	return (0);
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
