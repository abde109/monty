#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Opcode function prototypes */
void push(stack_t **stack, unsigned int line_number, const char *n);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
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
