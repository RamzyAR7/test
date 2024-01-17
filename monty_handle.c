#include "monty.h"

void check_the_arg(int args, char *argv[])
{
	int length_of_argv;

	if (args != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	length_of_argv = strlen(argv[1]);
	if (argv[1][length_of_argv - 1] != 'm' || argv[1][length_of_argv - 2] != '.')
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
void check_open_file(char *argv[])
{
	char line[bufsize];
	size_t num_line = 0;

	char *chank;
	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		num_line++;
		chank = strtok(line, " \t\n");
		if (chank != NULL)
		{
			check_on_chank(chank, num_line);
		}
	}
	fclose(fp);
}
void check_on_chank(char *chank, int num_line)
{
	int i, idx = 0;
	instruction_t arr[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{NULL, NULL}};

	for (i = 0; arr[i].opcode; i++)
	{
		if (strcmp(chank, arr[i].opcode) == 0)
		{
			idx = 1;
			arr[i].f(&head, (unsigned int)num_line);
		}
	}
	if (idx == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", num_line, chank);
		exit(EXIT_FAILURE);
	}
}
