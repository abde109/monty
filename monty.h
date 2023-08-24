#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue).
 * @n: Integer value.
 * @next: Pointer to the next element of the stack (or queue).
 */
typedef struct stack_s
{
	int n;
	struct stack_s *next;
} stack_t;

/**
 * op_func_t - Typedef for opcode functions.
 */
typedef void (*op_func_t)(stack_t **stack, unsigned int line_number);

/* Opcode function prototypes */
void push(stack_t **stack, unsigned int line_number, const char *n);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void mul_opcode(stack_t **stack, unsigned int line_number);
void mod_opcode(stack_t **stack, unsigned int line_number);
void pchar_opcode(stack_t **stack, unsigned int line_number);
void pstr_opcode(stack_t **stack, unsigned int line_number);
void rotl_opcode(stack_t **stack, unsigned int line_number);
void rotr_opcode(stack_t **stack, unsigned int line_number);
void stack_opcode(stack_t **stack, unsigned int line_number);
void queue_opcode(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
