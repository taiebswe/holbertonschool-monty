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
        printf("CAN'T POP AN EMPTY STACK\n");
        exit(EXIT_FAILURE);
    }
    topNode = (*stack);

    if (*stack)
        (*stack)->prev = NULL;

    *stack = (*stack)->next;
    free(topNode);
    /* Add logic to remove the top element from the stack */
}