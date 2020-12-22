#include "monty.h"

/**
 * checkFunction - function that selects the correct function to perform the
 *               operation asked by the user.
 *
 * @token: This is the input operator
 * @line_number: line number read
 * @head: pointer to head of the list
 */
void checkFunction(char *token, unsigned int line_number, stack_t **head)
{
	instruction_t func_code[] = {
		{ "push", f_push },
		{ "pall", f_pall },
		{ "pint", f_pint },
		{ "pop", f_pop },
		{ "swap", f_swap },
		{NULL, NULL}
	};
	int i = 0;

	while (i < 5)
	{
		if (strcmp(func_code[i].opcode, token) == 0)
		{
			func_code[i].f(head, line_number);
			break;
		}
		i++;
	}
	if (i == 5)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, token);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_push - checks if the instruction read is "push"
 *
 * @s: instruction passed
 * Return: 0 on failure, 1 on succes
 */
int check_push(char *s)
{
	char *accept = "push";
	int i = 0;

	if (s == NULL)
		return (0);
	while (s[i] == accept[i] && accept[i] != '\0')
		i++;
	if (i == 4)
		return (1);
	return (0);
}

/**
 * _parseArg - checks if the argument of push is a integer
 * @c: argument
 * Return: 1 on Success, or 0 on failure
 */
int _parseArg(char *c)
{
	int idx = 0;

	while (((c[idx] <= '9' && c[idx] >= '0') || (c[0] == '-')) && c != 0)
	{
		if (c[idx + 1] == 0)
			return (1);
		idx++;
	}
	return (0);
}
