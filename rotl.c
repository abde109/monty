#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    stack_t *new_last;

    (void)line_number;

    if (current != NULL && current->next != NULL)
    {
        *stack = current->next;
        (*stack)->prev = NULL;

        new_last = *stack;
        while (new_last->next != NULL)
            new_last = new_last->next;

        new_last->next = current;
        current->prev = new_last;
        current->next = NULL;
    }
}
