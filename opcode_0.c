#include "monty.h"

void push_opcode(stack_t **stack, unsigned int line_number)
{
	char *input;
	int i, len, num;
	char *sec = strtok(NULL, " \t\n");

	len = strlen(sec);
	input = malloc(sizeof(len));

	for (i = 0; sec[i]; i++)
	{
		if (sec[i] >= '0' && sec[i] <= '9')
		{
			input[i] = sec[i];
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction push", line_number);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(input);

	add_stack(stack, num);
}
stack_t *add_stack(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *access;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
	{

		*head = new;
	}
	else
	{
		access = *head;
		*head = new;
		access->prev = new;
		new->next = access;
	}
	return (*head);
}
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}
size_t print_stack(const stack_t *h)
{
	unsigned int num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		num++;
	}
	return (num);
}
