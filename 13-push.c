#include "monty.h"
/**
 * insert_to_stack - add node to the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void insert_to_stack(stack_t **head, unsigned int line_number)
{
int n, j = 0, flag = 0;

if (interpreter.arg)
{
if (interpreter.arg[0] == '-')
j++;
for (; interpreter.arg[j] != '\0'; j++)
{
if (interpreter.arg[j] > 57 || interpreter.arg[j] < 48)
flag = 1; }
if (flag == 1)
{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE); }}
else
{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE); }
n = atoi(interpreter.arg);
if (interpreter.lifi == 0)
add_node(head, n);
else
enqueue(head, n);
}
