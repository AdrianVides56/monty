#include "monty.h"

/**
 * _errors - manages the errors
 * @errornum: number of error
 * @line_number: line number read
 * @stack: pointer to list's head
 */
void _errors(int errornum, unsigned int __attribute__((unused)) line_number,
	     stack_t **stack)
{
	char *malloc_f = "Error: malloc failed\n";

	if (errornum == 1)
	{
		free_list(*stack);
		write(2, malloc_f, strlen(malloc_f));
		exit(EXIT_FAILURE);
	}
	if (errornum == 2) /*Incorrect use of push*/
	{
		free_list(*stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 3) /*pint failed*/
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 4) /*pop failed*/
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (errornum == 5) /*swap failed*/
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
}
