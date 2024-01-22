#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct interpreter_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct interpreter_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  interpreter_t;
extern interpreter_t interpreter;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void insert_to_stack(stack_t **head, unsigned int number);
void print_stack(stack_t **head, unsigned int number);
void print_top_int(stack_t **head, unsigned int number);
int execute_opcode(char *content, stack_t **head, unsigned int line_number, FILE *file);
void free_stack(stack_t *head);
void remove_top(stack_t **head, unsigned int line_number);
void stack_swap(stack_t **head, unsigned int line_number);
void add_stack(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void stack_sub(stack_t **head, unsigned int line_number);
void divide_top(stack_t **head, unsigned int line_number);
void multiply_elements(stack_t **head, unsigned int line_number);
void stack_modula(stack_t **head, unsigned int line_number);
void print_char_stack(stack_t **head, unsigned int line_number);
void display_stack_str(stack_t **head, unsigned int line_number);
void rotate_left(stack_t **head, unsigned int line_number);
void rotate_right(stack_t **head, __attribute__((unused)) unsigned int line_number);
void add_node(stack_t **head, int n);
void enqueue(stack_t **head, int n);
void enable_queue(stack_t **head, unsigned int line_number);
void stack_mode(stack_t **head, unsigned int line_number);
#endif
