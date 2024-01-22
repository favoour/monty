#include "monty.h"
/**
 * multiply_elements - multiplies the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void multiply_elements(stack_t **head, unsigned int line_number)
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
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
h = *head;
result = h->next->n * h->n;
h->next->n = result;
*head = h->next;
free(h);
}
