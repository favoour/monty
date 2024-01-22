#include "monty.h"
/**
 * add_stack - adds the top two elements of the stack.
 * @head: The stack head
 * @line_number: line_number
 * Return: Always return nothing
*/
void add_stack(stack_t **head, unsigned int line_number)
{
stack_t *h;
int len = 0, result;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
result = h->n + h->next->n;
h->next->n = result;
*head = h->next;
free(h);
}
