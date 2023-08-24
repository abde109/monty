#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    if (current != NULL && current->next != NULL)
    {
        while (current->next != NULL)
            current = current->next;
        current->next = *stack;
        current->prev->next = NULL;
        (*stack)->prev = current;
        *stack = current;
    }
}
