#include "monty.h"
/**
 * s_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void s_div(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int node_count = 0, result;

	current_node = *head;
	while (current_node)
	{
		current_node = current_node->next;
		node_count++;
	}

	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	result = current_node->next->n / current_node->n;
	current_node->next->n = result;
	*head = current_node->next;
	free(current_node);
}
