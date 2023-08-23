#include "monty.h"

void push(stack_t **stack, unsigned int line_number, const char *n)
{
    stack_t *new_node;
    int num = atoi(n);

    (void)line_number;
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->next = *stack;
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)line_number;
    current = *stack;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
