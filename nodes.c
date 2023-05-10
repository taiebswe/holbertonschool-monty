#include "monty.h"

stack_t *create_node(unsigned int number)
{
    stack_t *new;

    new = malloc(sizeof(stack_t) * 1);

    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;
    new->prev = NULL;

    return new;
}

void (*get_op_func(char *op))(stack_t **, unsigned int)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {0, NULL},
    };

    int i = 0;

    while (ops[i].opcode != NULL)
    {
        if (strcmp(op, ops[i].opcode) == 0)
            return ops[i].f;
        i++;
    }

    return (NULL);
}