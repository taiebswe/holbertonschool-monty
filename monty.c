#include "monty.h"

int isnumber(char *data)
{
    int i = 0;

    if (data == NULL)
        return (0);

    if (data[0] == '-')
        i++;

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
        EXIT_STATUS = EXIT_FAILURE;
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
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        EXIT_STATUS = EXIT_FAILURE;
        return;
    }
    printf("%d\n", (*stack)->n);
    /* Print the value at the top of the stack */
}

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
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        EXIT_STATUS = EXIT_FAILURE;
        return;
    }
    topNode = (*stack);

    if (*stack)
        (*stack)->prev = NULL;

    *stack = (*stack)->next;
    free(topNode);
    /* Add logic to remove the top element from the stack */
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    return;
}

void swap(stack_t **stack, unsigned int line_number)
{
    int tmp;

    if (!stack || !(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        EXIT_STATUS = EXIT_FAILURE;
        return;
    }

    tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
}

void add(stack_t **stack, unsigned int line_number)
{
    if (!stack || !(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        EXIT_STATUS = EXIT_FAILURE;
        return;
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}