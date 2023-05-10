#include "monty.h"
char *value;

int main(int argc, char **argv)
{
    FILE *file;
    ssize_t nread;
    char *line;
    size_t len = 0;
    char *op;
    unsigned int line_count = 0;
    stack_t *stack = NULL;
    void (*do_operation)(stack_t **, unsigned int);
    (void)argc;

    file = read_file(argv[1]);

    while ((nread = getline(&line, &len, file)) != -1)
    {
        line_count++;
        tokenize_line(line, &op, &value);
        if (!op && !value)
            continue;

        if (op)
            do_operation = get_op_func(op);
        if (do_operation)
        {
            // Adding condition to check if value is working with atoi
            do_operation(&stack, line_count);
        }
    }

    fclose(file);
    free(line);

    return (0);
}
