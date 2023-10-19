#include "monty.h"
/**
 * rotl - Rotates the stack to the top
 * @head: Pointer to the head of the stack
 * @counter: Line number
 *
 * Return: No return value
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *temp = *head, *new_head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	new_head = (*head)->next;
	new_head->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = new_head;
}
