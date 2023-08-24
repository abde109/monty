#include "monty.h"

void handle_stack(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    queue_mode = 0;
}

void handle_queue(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    queue_mode = 1;
}
