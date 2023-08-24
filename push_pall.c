#include "monty.h"

void push(stack_t **stack, unsigned int line_number, const char *n)
{
    stack_t *new_node;

    if (n == NULL || atoi(n) == 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(n);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}
