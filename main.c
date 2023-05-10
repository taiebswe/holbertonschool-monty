#include "monty.h"

int main(void)
{
    FILE *file;
    ssize_t nread;
    char *line;
    size_t len = 0;
    char *op;
    char *value;
    unsigned int data = 0;
    int line_count = 0;
    stack_t *stack = NULL;
    void (*do_operation)(stack_t **, unsigned int);

    file = read_file("bytecodes/000.m");

    while ((nread = getline(&line, &len, file)) != -1)
    {
        tokenize_line(line, &op, &value);
        if (op)
            do_operation = get_op_func(op);
        if (do_operation)
        {
            // Adding condition to check if value is working with atoi
            if (value)
                data = atoi(value);
            do_operation(&stack, data);
        }
        line_count++;
    }

    fclose(file);
    free(line);

    return (0);
}
