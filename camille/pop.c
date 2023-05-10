#include "monty.h"

/**
 * pop - removes first element of stack
 * @stack: linked list
 * @line_number: line number
 *
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *topNode = NULL;
    /* Implementation of pop opcode */
    if (!*stack)
    {
        fprintf(stderr, "L<line_number>: can't pop an empty stack\n", line_number);
        EXIT_STATUS = EXIT_FAILURE;
        break;
    }
    topNode = (*stack);

    if (*stack)
        (*stack)->prev = NULL;

    *stack = (*stack)->next;
    free(topNode);
    /* Add logic to remove the top element from the stack */
}
