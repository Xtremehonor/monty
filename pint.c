#include "monty.h"
/**
 * pint - Displays the value
 * at the top of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 * Return: No return value.
*/
void pint (stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
