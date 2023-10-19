	#include "monty.h"
	/**
	 * add - Adds the top two elements of the stack.
	 * @head: Pointer to the stack head
	 * @counter: Line number
	 * Return: No return value
	 */
	void add(stack_t **head, unsigned int counter)
	{
	stack_t *current;
	int stackLength = 0, sum;

	current = *head;

	while (current)
	{
		current = current->next;
		stackLength++;
	}

	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*head = current->next;
	free(current);
	}
