#include "monty.h"
/**
 * rotr_opcode - rotates the stack to the bottom
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int number;

	(void)line_number;
	if (*stack && (*stack)->next)
	{
		temp = *stack;

		while (temp->next)
		{
			temp = temp->next;
		}
		number = temp->n;
		while (temp->prev)
		{
			temp->n = (temp->prev)->n;
			temp = temp->prev;
		}
		temp->n = number;
	}
}
/**
 * rotl_opcode - rotates the stack to the top
 * @stack: stack
 * @line_number: line number
 * Return: void
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int replace;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		replace = (*stack)->n;

		(void)line_number;
		while (temp->next)
		{
			temp->n = (temp->next)->n;
			temp = temp->next;
		}
		temp->n = replace;
	}
}
