#include "monty.h"

int is_number(const char *str)
{
    if (str == NULL)
        return 0;

    if (*str == '-' || *str == '+')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

void push(stack_t **stack, unsigned int line_number, const char *n)
{
    stack_t *new_node;
    int num;

    if (n == NULL || !is_number(n))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(n);
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
