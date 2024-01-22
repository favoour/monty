#include "monty.h"
/**
 * print_stack - prints the stack
 * @head: stack head
 * @line_number: no used
 * Return: no return
*/
void print_stack(stack_t **head, unsigned int line_number)
{
stack_t *h;
(void)line_number;

h = *head;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
