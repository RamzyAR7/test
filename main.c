#include "monty.h"
stack_t *head = NULL;
int main(int args, char *argv[])
{
	check_the_arg(args, argv);
	check_open_file(argv);
	return (0);
}
