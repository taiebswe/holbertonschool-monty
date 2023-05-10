
#include "monty.h"

FILE *read_file(char *path)
{
    FILE *file;

    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("ERROR OPENING THE FILE\n");
        exit(EXIT_FAILURE);
    }

    return file;
}

void tokenize_line(char *line, char **op, char **value)
{

    // USE STRTOK HERE TO GET:
    // - OPCODE
    // - Value (which is the number to push into the stack)
    *op = strtok(strdup(line), " $\n\t");
    *value = strtok(NULL, " $\n\t");
    // if (value != NULL)
    //     data = atoi(value);

    // // FOR PUSH and OP operations with value
    // if (op != NULL && value != NULL)
    //     printf("OP: %s -> %d\n", op, data);
    // // FOR PALL and OP operations without a value
    // else if (op != NULL && value == NULL)
    //     printf("OP: %s\n", op);
}
