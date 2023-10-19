#include "monty.h"
/**
 * pop - Removes the top element of the stack
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 *
 */
void pop(stack_t **head, unsigned int counter)
{
	stack_t *stack_head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack_head = *head;
	*head = stack_head->next;
	free(stack_head);
}
