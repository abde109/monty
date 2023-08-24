#include "monty.h"

void stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    queue_mode = 0;
}

void queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    queue_mode = 1;
}
