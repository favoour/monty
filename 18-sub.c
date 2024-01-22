#include "monty.h"
/**
 *stack_sub- sustration
*@head: stack head
*@line_number: line_number
*Return: no return
*/
void stack_sub(stack_t **head, unsigned int line_number)
{
stack_t *result;
int sus, nodes;

result = *head;
for (nodes = 0; result != NULL; nodes++)
result = result->next;
if (nodes < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
fclose(interpreter.file);
free(interpreter.content);
free_stack(*head);
exit(EXIT_FAILURE);
}
result = *head;
sus = result->next->n - result->n;
result->next->n = sus;
*head = result->next;
free(result);
}
