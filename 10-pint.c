#include "monty.h"
/**
 * print_top_int - prints the top
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void print_top_int(stack_t **head, unsigned int line_number)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
