#include "monty.h"
/**
 * remove_top - prints the top
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void remove_top(stack_t **head, unsigned int line_number)
{
stack_t *h;

if (*head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
*head = h->next;
free(h);
}
