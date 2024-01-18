#include "monty.h"
/**
 * push_opcode - opcode push
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	char *input;
	int i, len, num;
	char *sec = strtok(NULL, " \t\n");

	if (sec == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	len = strlen(sec);
	input = malloc(sizeof(len));
	if (input == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	for (i = 0; sec[i]; i++)
	{
		if (sec[i] == '-')
		{
			input[i] = sec[i];
		}
		else if (sec[i] >= '0' && sec[i] <= '9')
		{
			input[i] = sec[i];
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(*stack);
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	input[i] = '\0';
	num = atoi(input);
	free(input);
	add_stack(stack, num);
}
/**
 * add_stack - add stack
 * @head: head
 * @n: number
 * Return: void
 */
void add_stack(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		exit(EXIT_FAILURE);
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
		if (global_var.flag == 0)
		{
			new->next = *head;
			(*head)->prev = new;
			*head = new;
		}
		else if (global_var.flag == 1)
		{
			tmp = *head;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = new;
			new->prev = tmp;
		}
	}
}
/**
 * pall_opcode - opcode pall
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
/**
 * pint_opcode - opcode pint
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop_opcode - opcode pop
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}
