#include "monty.h"

stack_t *create_node()
{
    stack_t *new;

    if (!isnumber(value))
    {
        return (NULL);
    }

    new = malloc(sizeof(stack_t) * 1);

    if (new == NULL)
        return (NULL);

    new->n = atoi(value);
    new->next = NULL;
    new->prev = NULL;

    return new;
}

void (*get_op_func(char *op, int line_count))(stack_t **, unsigned int)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {0, NULL},
    };

    int i = 0;

    while (op && ops[i].opcode != NULL)
    {
        if (strcmp(op, ops[i].opcode) == 0)
            return ops[i].f;
        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_count, op);
    EXIT_STATUS = EXIT_FAILURE;

    return (NULL);
}