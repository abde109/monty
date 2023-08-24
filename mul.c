#include "monty.h"

void mul_opcode(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}
