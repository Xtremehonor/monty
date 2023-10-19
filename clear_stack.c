#include "monty.h"
/**
* clear_stack - Deallocates memory
* for a doubly linked list (stack).
* @head: Pointer to the head of the stack
*/
void clear_stack(stack_t *head)
{
stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
