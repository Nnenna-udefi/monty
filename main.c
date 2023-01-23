#include "monty.h"


/**
* opcode_finder - find opcode
* @stack: stack pointer
* @opcode: user input opcode
* @line_number: line number
* Return: Always 1 (Success) or stderr
**/
int find_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i;

instruction_t opcodes[] = {
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"pint", pint},
		{"push", push},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	if (opcode && !opcodes[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	return (1);
}


/**
* main - Process Monty byte codes from a file passed in as an argument
* @argc: size of argv
* @argv: A double pointer contain the arguments
* Return: EXIT_SUCCESS if no errors or EXIT_FAILURE
**/

int main(__attribute__((unused)) int argc, char const *argv[])
{
	FILE *mf;
	char *buff = NULL, *opcode, *n;
	size_t i = 0;
	ssize_t readl = 1;
	unsigned int line_number = 0;
	stack_t *stack = NULL, *current;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	mf = fopen(argv[1], "r");
	buf.mf = file;
	
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(1);
	}
	while (readl > 0)
	{
		readl = getline(&buff, &lol, mf);
		buf.buff = command;
		line_number++;
		opcode = strtok(buff, DELIMATOR);
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (!strcmp(opcode, "nop"))
			continue;
		else if (!strcmp(opcode, "push"))
		{
			n = strtok(NULL, DELIMATOR);
			push(&stack, line_number);
		}
		else
			find_opcode(&stack, opcode, line_number);
	}
	fclose(mf);
	free(buff);
	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
	return (0);
}

/**
* free_stack - free the double linked list
* @stack: pointer to the head of the list
**/
void free_stack(stack_t *stack)
{
	stack_t *next;
	
	while (stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
