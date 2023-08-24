#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    temp->next = (*stack)->next;
    temp->prev = *stack;
    (*stack)->next = temp;

    if (temp->next)
        temp->next->prev = temp;
}
