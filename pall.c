#include "monty.h"
/**
 * pall - prints values from the stack
 * @head: pointer to the stack head
 * @counter: no of each line in the file
 * Return: none
*/
void pall(stack_t **head, unsigned int counter)
{
	stack_t *head_stack;
	(void)counter;

	head_stack = *head;
	if (head_stack == NULL)
		return;
	while (head_stack)
	{
		printf("%d\n", head_stack->n);
		head_stack = head_stack->next;
	}
}
