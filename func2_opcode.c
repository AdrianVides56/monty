#include "monty.h"

/**
 * f_nop - does nothing
 * @head: pointer to list's head
 * @line_number: line number read
 */
void f_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * f_add - Adds two top elements on the stack
 * @head: This is the list head
 * @line_number: Line number read
 *
 */

void f_add(stack_t **head, unsigned int line_number)
{
	stack_t *aux = *head;

	if (*head == NULL || aux->next == NULL)
	{
		_errors(6, line_number, head);
	}
	while (aux != NULL)
	{
		if (aux->next == NULL)
		{
			aux->prev->n += aux->n;
			f_pop(head, line_number);
		}
		aux = aux->next;
	}
}
