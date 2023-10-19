#include "monty.h"
/**
 * mod - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void mod(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int node_count = 0, remainder;

	current_node = *head;
	while (current_node)
	{
		current_node = current_node->next;
		node_count++;
	}

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	current_node = *head;
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	remainder = current_node->next->n % current_node->n;
	current_node->next->n = remainder;
	*head = current_node->next;
	free(current_node);
}
