
int main(int argc, char **argv)
{
	FILE *file;
	ssize_t line_len;
	size_t size;
	char *buff;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open the file %s\n", argv[1]);
        exit(EXIT_FAILURE);
	}
	line_len = getline(&buff, &size, file);
	printf("line: %s, len: %ld\n", buff, line_len);
	return (0);
}
