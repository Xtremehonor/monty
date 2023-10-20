#include "monty.h"

void do_nothing(void);
MontyContext_t MontyContext = {NULL, NULL, NULL, 0};
/**
 * main - Monty code interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on successful execution
 */
int main(int argc, char *argv[])
{
char *line_content;
FILE *monty_file;
size_t buffer_size = 0;
ssize_t read_line = 1;
stack_t *stack = NULL;
unsigned int counter = 0;

if (argc != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
monty_file = fopen(argv[1], "r");
MontyContext.file = monty_file;

if (!monty_file)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}
while (read_line > 0)
{
	line_content = NULL;
	read_line = getline(&line_content, &buffer_size, monty_file);
	MontyContext.content = line_content;
	counter++;

	if (read_line > 0)
	{
		execute(line_content, &stack, counter, monty_file);
	}
	free(line_content);
}

clear_stack(stack);
fclose(monty_file);
return (0);
}
/**
 * do_nothing - This function does nothing.
 *
 * Return: No return value.
 */
void do_nothing(void)
{
}
