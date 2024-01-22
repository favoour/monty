#include "monty.h"
/**
 * enable_queue - prints the top
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void enable_queue(stack_t **head, unsigned int line_number)
{
(void)head;
(void)line_number;
interpreter.lifi = 1;
}

/**
 * enqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void enqueue(stack_t **head, int n)
{
stack_t *new_node, *result;

result = *head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = n;
new_node->next = NULL;
if (result)
{
while (result->next)
result = result->next;
}
if (!result)
{
*head = new_node;
new_node->prev = NULL;
}
else
{
result->next = new_node;
new_node->prev = result;
}
}
