#include "monty.h"

/**
 * push - adding element to stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int number)
{
    stack_t *newNode;

    newNode = create_node(number);

    // TODO -> Consider maybe adding an error or something
    if (newNode == NULL)
    {
        printf("WARNING: NEW NODE IS NULL\n");
        return;
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
    (void)line_number;

    if (!*stack)
    {
        printf("CAN'T PINT, STACK EMPTY");
        exit(EXIT_FAILURE);
    }
    printf("%d", (*stack)->n);
    /* Print the value at the top of the stack */
}
