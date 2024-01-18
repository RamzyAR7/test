#include "monty.h"
stack_t *head = NULL;
/**
 * main - interpreter for monty codes
 * @args: number of arguments
 * @argv: array of arguments
 * Return: void
*/
int main(int args, char *argv[])
{
	check_the_arg(args);
	check_open_file(argv);
	if (head != NULL)
	{
		free_stack(head);
	}
	return (0);
}
