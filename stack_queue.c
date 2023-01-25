#include "monty.h"
/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer
 * @line_number: number of lines in the file
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	buf.flag = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer
 * @line_number: number of lines in the file
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	buf.flag = 1;
}
