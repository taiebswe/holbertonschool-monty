
#include "monty.h"

FILE *read_file(char **argv)
{
    FILE *file;

    if (argv[1] == NULL)
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

    return file;
}

void tokenize_line(char *line, char **op, char **value)
{
    *op = strtok(line, " $\n\t");
    *value = strtok(NULL, " $\n\t");
}
