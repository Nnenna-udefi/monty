#include  "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: doublepointer to the dll
 * @line_number: number of lines in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || (*stack) == NULL || len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to dll
 * @line_number: number of lines in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: an't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}


/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer
 * @line_number: number of lines in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;

	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
			break;
		printf("%c\n", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}


/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to dll
 * @line_number: number of lines in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *temp;
	(void)line_number;

	head = *stack;
	if (!head || !head->next)
		return;
	temp = head->next;
	temp->prev = NULL;

	while (head->next != NULL)
		head = head->next;
	head->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = head;
	(*stack) = temp;
}


/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer
 * @line_number: number of lines in the list
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;

	if (!temp || !temp->next)
		return;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}
