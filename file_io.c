
#include "monty.h"

FILE *read_file(char *path)
{
    FILE *file;

    file = fopen(path, "r");
    if (file == NULL)
    {
        fprintf(stderr, "USAGE: monty file\n");
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
}
