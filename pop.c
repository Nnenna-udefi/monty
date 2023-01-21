#include "monty.h"

/**
 * pop - function that removes the top element of the stack
 * @stack: double pointer to the linked list
 * @line_number: number of lines in the file
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *end_pointer;

	if (stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (*stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		end_pointer = *stack;
		*stack = (*stack)->next;
		free(end_pointer);
	}
}
