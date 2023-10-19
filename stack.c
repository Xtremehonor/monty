#include "monty.h"
/**
 * s_stack - Sets the format of the data
 *  to a stack (LIFO)
 * @head: Pointer to the head of the stack
 * @counter: Line number (unused)
 *
 * Return: No return value
 */
void s_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	MontyContext.stackOrQueue = 0;
}
