#include "monty.h"

/**
 * f_nop - does nothing
 * @stack: pointer to list's head
 * @line_number: line number read
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	return;
	(void)line_number;
	(void)**stack;
}

/**
 * f_add - Adds two top elements on the stack
 * @head: This is the list head
 * @line_number: Line number read
 *
 */

void f_add(stack_t **head, unsigned int line_number)
{
	int sum;

	if (*head == NULL || ((*head)->prev == NULL && (*head)->next == NULL))
		_errors(6, line_number, head); /* Add failed */

	sum = (*head)->n + (*head)->next->n;
	f_pop(head, line_number);
	(*head)->n = sum;
}

/**
 * f_sub - Adds two top elements on the stack
 * @head: This is the list head
 * @line_number: Line number read
 *
 */
void f_sub(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (*head == NULL || aux->next == NULL)
	{
		_errors2(7, line_number, head);
	}
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->prev->n -= aux->n;
			f_pop(head, line_number);
		}
		aux = aux->next;
	}
}

/**
 * f_mul - Adds two top elements on the stack
 * @head: This is the list head
 * @line_number: Line number read
 *
 */
void f_mul(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (*head == NULL || aux->next == NULL)
	{
		_errors2(8, line_number, head);
	}
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->prev->n *= aux->n;
			f_pop(head, line_number);
		}
		aux = aux->next;
	}
}
