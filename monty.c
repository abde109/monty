#include "monty.h"

char *read_line(FILE *file)
{
    char *line = NULL;
    int c;
    size_t size = 0;
    size_t len = 0;

    while ((c = fgetc(file)) != EOF && c != '\n')
    {
        if (len + 1 >= size)
        {
            size = size ? size * 2 : 1024;
            line = realloc(line, size);
        }
        line[len++] = c;
    }

    if (len == 0)
    {
        free(line);
        return (NULL);
    }

    line[len] = '\0';
    return (line);
}

int main(int argc, char *argv[])
{
    FILE *file;
    char *line;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char *opcode;
    char *argument;
    char *c;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((line = read_line(file)) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \t\r\n");
        argument = strtok(NULL, " \t\r\n");
        for (c = opcode; *c; c++)
        {
            if (!isalnum(*c))
            {
                *c = '\0';
                break;
            }
        }
        if (opcode == NULL || opcode[0] == '#' || isspace(opcode[0]))
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
            pall(&stack, line_number);
        else if (strcmp(opcode, "pint") == 0)
            pint(&stack, line_number);
        else if (strcmp(opcode, "pop") == 0)
            pop(&stack, line_number);
        else if (strcmp(opcode, "swap") == 0)
            swap(&stack, line_number);
        else if (strcmp(opcode, "add") == 0)
            add(&stack, line_number);
        else if (strcmp(opcode, "pop") == 0)
            pop(&stack, line_number);
        else if (strcmp(opcode, "div") == 0)
            div_opcode(&stack, line_number);
        else if (strcmp(opcode, "mul") == 0)
            mul_opcode(&stack, line_number);
        else if (strcmp(opcode, "mod") == 0)
            mod_opcode(&stack, line_number);
        else if (strcmp(opcode, "pchar") == 0)
            pchar_opcode(&stack, line_number);
        else if (strcmp(opcode, "pstr") == 0)
            pstr_opcode(&stack, line_number);
        else if (strcmp(opcode, "rotl") == 0)
            rotl_opcode(&stack, line_number);
        else if (strcmp(opcode, "rotr") == 0)
            rotr_opcode(&stack, line_number);
        else if (strcmp(opcode, "stack") == 0)
            stack_opcode(&stack, line_number);
        else if (strcmp(opcode, "queue") == 0)
            queue_opcode(&stack, line_number);

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
