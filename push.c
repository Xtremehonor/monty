#include "monty.h"
/**
 * push - Inserts a node onto the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number in the program.
 * Return: No return.
*/
void push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (MontyContext.arg)
	{
		if (MontyContext.arg[0] == '-')
			j++;
		for (; MontyContext.arg[j] != '\0'; j++)
		{
			if (MontyContext.arg[j] > 57 || MontyContext.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(MontyContext.file);
			free(MontyContext.content);
			clear_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(MontyContext.file);
		free(MontyContext.content);
		clear_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(MontyContext.arg);
	if (MontyContext.stackOrQueue == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
