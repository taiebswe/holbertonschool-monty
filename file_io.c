
#include "monty.h"

FILE *read_file(int argc, char **argv)
{
    FILE *file;

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

    return file;
}

void tokenize_line(char *line, char **op, char **value)
{
    *op = strtok(line, " $\n\t");
    *value = strtok(NULL, " $\n\t");
}
