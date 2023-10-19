#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void swap(stack_t **head, unsigned int counter)
{
stack_t *current;
int length = 0, temp;

current = *head;

while (current)
{
	current = current->next;
	length++;
}

if (length < 2)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
	fclose(MontyContext.file);
	free(MontyContext.content);
	clear_stack(*head);
	exit(EXIT_FAILURE);
}

	current = *head;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
