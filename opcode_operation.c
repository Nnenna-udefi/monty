#include "monty.h"

/**
 * add - opcode add adds the top two elements of the stack
 * @stack: double pointer to the linked list
 * @line_number: number of lines in the file
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int len;
	int sum;

	for (len = 0; temp != NULL; len++)
		temp = temp->next;

	if (stack == NULL || (*stack) == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}



/**
 * sub - subtracts the top two element
 * @stack: double pointer to the linked list
 * @line_number: number of lines in the file
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int len, result;

	for (len = 0; temp != NULL; len++)
		temp = temp->next;
	if (stack == NULL || (*stack) == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	temp->next->n = result;
	(*stack) = temp->next;
	free(temp);
}


/**
 * div - divides the next element by the top element in dll
 * @stack: head of dll
 * @line_number: line number
 */
void div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n /= result;
}


/**
 * mul - multiplies the top and the next numbers in dll
 * @stack: head of a dll
 * @line_number: line number in the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if ((*stack) == NULL || (*stack)->next == NULL || len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n *= tmp;
}

/**
 * mod - find the modulus of the top and next element in a dll
 * @stack: head of dll
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL || len(stack) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n;
	pop(stack, line_number);
	(*stack)->n %= result;
}
