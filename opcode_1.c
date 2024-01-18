#include "monty.h"
/**
 * add_opcode - adds the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack && (*stack)->next)
	{
		((*stack)->next)->n = (*stack)->n + ((*stack)->next)->n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
/**
 * nop_opcode - opcode nop
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
/**
 * sub_opcode - subtracts the top of the stack from the second top of the stack
 * @stack: stack
 * @line_number: line number
 */
void sub_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack && (*stack)->next)
	{
		((*stack)->next)->n = ((*stack)->next)->n - (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
/**
 * swap_opcode - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		if (second->next != NULL)
		{
			second->next->prev = first;
		}

		second->prev = NULL;
		second->next = first;
		first->prev = second;

		*stack = second;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		if (*stack)
		{
			free_stack(*stack);
		}
		exit(EXIT_FAILURE);
	}
}
