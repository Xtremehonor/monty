#include "monty.h"
/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void sub(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int difference, node_count;

	current_node = *head;
	for (node_count = 0; current_node != NULL; node_count++)
		current_node = current_node->next;

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	current_node = *head;
	difference = current_node->next->n - current_node->n;
	current_node->next->n = difference;
	*head = current_node->next;
	free(current_node);
}

