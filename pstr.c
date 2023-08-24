#include "monty.h"

void pstr_opcode(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    (void)line_number; 

    while (temp && temp->n > 0 && temp->n < 128)
    {
        putchar(temp->n);
        temp = temp->next;
    }
    putchar('\n');
}
