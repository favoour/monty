#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int n;
    struct StackNode *next;
} stack_t;

void add_stack(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);

struct {
    FILE *file;
    char *content;
} interpreter;

void free_stack(stack_t *head) {
    while (head) {
        stack_t *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    stack_t *stack = NULL;

    add_stack(&stack, 1);
    add_stack(&stack, 2);
    add_stack(&stack, 3);

    stack_t *current = stack;
    printf("Stack values:");
    while (current) {
        printf(" %d", current->n);
        current = current->next;
    }
    printf("\n");

    free_stack(stack);

    return 0;
}

void add_stack(stack_t **head, unsigned int line_number) {
    stack_t *h;
    int len = 0, result;

    h = *head;

    while (h) {
        h = h->next;
        len++;
    }

    if (len < 2) {
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

