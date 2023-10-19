#include "monty.h"
/**
 * pchar - Prints the character at the top of the stack, followed by a new line.
 * @head: Pointer to the head of the stack.
 * @counter: Line number.
 * Return: No return.
 */
void pchar(stack_t **head, unsigned int counter)
{
	stack_t *top;

	top = *head;
	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", top->n);
}
