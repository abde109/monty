#include "monty.h"

void rotr_opcode(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    temp = *stack;
    while (temp->next->next)
        temp = temp->next;

    temp->next->next = *stack;
    *stack = temp->next;
    temp->next = NULL;
}
