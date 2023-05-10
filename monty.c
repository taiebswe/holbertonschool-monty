#include "monty.h"

int isnumber(char *data)
{
    int i = 0;

    if (data == NULL)
        return (0);

    while (data[i])
    {
        if (!isdigit(data[i]))
            return (0);
        i++;
    }
    return (1);
}
/**
 * push - adding element to stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *newNode;
    (void)line_number;

    newNode = create_node();

    if (newNode == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (stack && *stack)
    {
        (*stack)->prev = newNode;
        newNode->next = *stack;
        *stack = newNode;
        return;
    }

    *stack = newNode;
}

/**
 * pall - print from the start node
 * @stack: the header
 * @line_number: for the error
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *head = *stack;
    /* Implementation of pall opcode */
    while (stack && *stack)
    {
        printf("%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }

    if (stack != NULL)
    {
        *stack = head;
    }
    /* Print all elements of the stack */
}

/**
 * pint - print int in top of stack
 * @stack: the header
 * @line_number: still don't know
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d", (*stack)->n);
    /* Print the value at the top of the stack */
}
