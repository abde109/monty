#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    if (current != NULL && current->next != NULL)
    {
        *stack = current->next;
        while (current->next != NULL)
            current = current->next;
        current->next = *stack;
        (*stack)->prev->next = NULL;
        (*stack)->prev = NULL;
    }
}
