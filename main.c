#include "monty.h"
global_t global_var = {0, NULL};
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
	if (global_var.head != NULL)
	{
		free_stack(global_var.head);
	}
	return (0);
}
