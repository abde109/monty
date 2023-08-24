#include "monty.h"

int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        char *opcode, *argument;
        int read;
        char buffer[1024]; /* or some other suitable size */

        read = fscanf(file, "%1023[^\n]\n", buffer);
        if (read == EOF)
            break;
        line = malloc(strlen(buffer) + 1);
        if (line == NULL)
        {
            fprintf(stderr, "Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(line, buffer);
        line_number++;
        opcode = strtok(line, " \n");
        argument = strtok(NULL, " \n");

        if (opcode == NULL || opcode[0] == '#')
            continue;

        if (strcmp(opcode, "push") == 0)
            push(&stack, line_number, argument);
        else if (strcmp(opcode, "pall") == 0)
            pall(&stack, line_number);
        else if (strcmp(opcode, "pint") == 0)
            pint(&stack, line_number);
        else if (strcmp(opcode, "pop") == 0)
            pop(&stack, line_number);
        else if (strcmp(opcode, "swap") == 0)
            swap(&stack, line_number);
        if (strcmp(opcode, "add") == 0)
            add(&stack, line_number);
        else if (strcmp(opcode, "nop") == 0)
            nop(&stack, line_number);
        else if (strcmp(opcode, "sub") == 0)
            sub(&stack, line_number);
        else if (strcmp(opcode, "div") == 0)
            divide(&stack, line_number);
        else if (strcmp(opcode, "mul") == 0)
            mul(&stack, line_number);
        else if (strcmp(opcode, "mod") == 0)
            mod(&stack, line_number);
        else if (strcmp(opcode, "pchar") == 0)
            pchar(&stack, line_number);
        else if (strcmp(opcode, "pstr") == 0)
            pstr(&stack, line_number);
        else if (strcmp(opcode, "rotl") == 0)
            rotl(&stack, line_number);
        else if (strcmp(opcode, "rotr") == 0)
            rotr(&stack, line_number);
        else if(strcmp(opcode, "stack") == 0)
            handle_stack(&stack, line_number);
        else if (strcmp(opcode, "queue") == 0)
            handle_queue(&stack, line_number);

        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            free_stack(stack);
            fclose(file);
            exit(EXIT_FAILURE);
        }

        free(line);
    }

    free_stack(stack);
    fclose(file);
    return (EXIT_SUCCESS);
}
