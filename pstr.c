#include "monty.h"
/**
 * pstr - Prints the string starting at the
 * top of the stack, followed by a new line.
 * @head: Pointer to the head of the stack.
 * @counter: Line number.
 * Return: No return.
 */
void pstr(stack_t **head, unsigned int counter)
{
stack_t *current_node;

(void)counter;
current_node = *head;

while (current_node)
{
	if (current_node->n > 127 || current_node->n <= 0)
	{
		break;
	}
	printf("%c", current_node->n);
	current_node = current_node->next;
}
printf("\n");
}
