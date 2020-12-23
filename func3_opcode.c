#include "monty.h"

/**
 * f_mod - calcs the module of the two top elements on the stack
 * @head: This is the list head
 * @line_number: Line number read
 *
 */
void f_mod(stack_t **head, unsigned int line_number)
{
	int mod;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		_errors2(10, line_number, head); /* mod failed */
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	mod = (*head)->next->n % (*head)->n;
	f_pop(head, line_number);
	(*head)->n = mod;
}



/**
 * f_pchar -  prints the char at the top of the stack, followed by a new line
 *
 * @head: This is the list head
 * @line_number: Line number read
 *
 */
void f_pchar(stack_t **head, unsigned int line_number)
{

	if (*head == NULL)
	{
		_errors2(11, line_number, head); /* pchar failed */
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_list(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * f_pstr - prints the string starting at the top of the stack,
 *          followed by a new line.
 *
 * @head: This is the list head
 * @line_number: Line number read
 *
 */
void f_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (*head == NULL)
	{
		printf("\n");
		return;
	}
	while (aux != NULL)
	{
		if (aux->n <= 0 || aux->n > 127)
			break;
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
	(void)line_number;
}
