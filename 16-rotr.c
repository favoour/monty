#include "monty.h"
/**
 *rotate_right- rotates the stack to the bottom
*@head: stack head
*@counter: line_number
*Return: no return
*/
void rotate_right(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
stack_t *copy;

copy = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
while (copy->next)
{
copy = copy->next;
}
copy->next = *head;
copy->prev->next = NULL;
copy->prev = NULL;
(*head)->prev = copy;
(*head) = copy;
}
