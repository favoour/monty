#include "monty.h"
/**
 *rotate_left- rotates the stack to the top
*@head: stack head
*@line_number: line_number
*Return: no return
*/
void rotate_left(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
stack_t *tmp = *head, *result;

if (*head == NULL || (*head)->next == NULL)
{
return;
}
result = (*head)->next;
result->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = result;
}
