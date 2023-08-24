#include "monty.h"

void rotl_opcode(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;
    while (temp->next)
        temp = temp->next;
    temp->next = *stack;
}
