#include "monty.h"
/**
 * rotr - Rotates the stack to the bottom
 * @head: Pointer to the head of the stack
 * @counter: Line number (unused)
 *
 * Return: No return value
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head;
	stack_t *last;

	if (*head == NULL || (*head)->next == NULL)
		return;

	while (current->next)
		current = current->next;

	last = current;

	last->next = *head;
	last->prev->next = NULL;
	last->prev = NULL;
	(*head)->prev = last;
	(*head) = last;
}

