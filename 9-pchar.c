#include "monty.h"
/**
 * print_char_stack - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void print_char_stack(stack_t **head, unsigned int line_number)
{
stack_t *h;

h = *head;
if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
if (h->n > 127 || h->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
printf("%c\n", h->n);
}
