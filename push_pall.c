#include "monty.h"

void push(stack_t **stack, unsigned int line_number, const char *n)
{
    stack_t *new_node;

    if (n == NULL || !is_number(n))
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

int is_number(const char *str)
{
    if (str == NULL)
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str != '\0')
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
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
