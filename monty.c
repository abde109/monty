#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        char *opcode = strtok(line, " \t\r\n");
        char *argument = strtok(NULL, " \t\r\n");

        if (opcode == NULL || opcode[0] == '#')
            continue;

        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL || !isdigit(argument[0]))
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, line_number, argument);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(&stack, line_number);
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add(&stack, line_number);
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            nop(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    return (EXIT_SUCCESS);
}
