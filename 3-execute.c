#include "monty.h"
/**
* execute_opcode - executes the opcode
* @stack: head linked list - stack
* @line_number: The line number
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute_opcode(char *content, stack_t **stack, unsigned int line_number, FILE *file)
{
instruction_t instructions[] = {
{"push", insert_to_stack}, {"pall", print_stack}, {"pint", print_top_int},
{"pop", remove_top},
{"swap", stack_swap},
{"add", add_stack},
{"nop", _nop},
{"sub", stack_sub},
{"div", divide_top},
{"mul", multiply_elements},
{"mod", stack_modula},
{"pchar", print_char_stack},
{"pstr", display_stack_str},
{"rotl", rotate_left},
{"rotr", rotate_right},
{"queue", enable_queue},
{"stack", stack_mode},
{NULL, NULL}
};
unsigned int i = 0;
char *opcode;

opcode = strtok(content, " \n\t");
if (opcode && opcode[0] == '#')
return (0);
interpreter.arg = strtok(NULL, " \n\t");
while (instructions[i].opcode && opcode)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{	instructions[i].f(stack, line_number);
return (0);
}
i++;
}
if (opcode && instructions[i].opcode == NULL)
{ fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE); }
return (1);
}
