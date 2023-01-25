#include "monty.h"
/**
 * nop - function to do nothing
 * @stack: double pointer to the doubly linked list
 * @line_number: number of lines in the file
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pall - function to print stack's elements
 * @line_number: will not be used , we usse attribute not void
 * @stack: pointer to the head of the doubly linked list
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		return;
	while (current != NULL)
	{
		current = *stack;
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * push - pushes an element to the stack
 * @stack: double pointer to the doubly liked list
 * @n: integer
 * @line: line where there is an error
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int i;
	char *n = malloc(sizeof(char));

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i]; i++)
	{
		if (n[0] == '-' && i == 0)
			continue;
		if (n[i] < 48 || n[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * swap - swaps the value of the top two elements to the stack
 * @stack: pointer that point to stack
 * @line_number: line number of instruction
 * Return: void, exit with -1 on failure
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pint - prints all the values at the top of the stack
 * @stack: double pointer to the head;
 * @line_number: number of lines
 */
void pint(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
