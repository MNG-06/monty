#include "monty.h"

/**
 * _pint - prints the value from the top of the stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _pint(stack_t **stack, unsigned int line_nb)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_nb);
        META.error = 1;
        return;
    }
    
    printf("%d\n", (*stack)->n);
}

/**
 * _pall - prints all values from the stack, from top to bottom
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _pall(stack_t **stack, unsigned int line_nb)
{
    stack_t *cur = *stack;
    (void)line_nb;

    while (cur)
    {
        printf("%d\n", cur->n);
        cur = cur->next;
    }
}

/**
 * _nop - does absolutely nothing
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _nop(stack_t **stack, unsigned int line_nb)
{
    (void)stack;
    (void)line_nb;
}

/**
 * _pchar - prints the value at the top of the stack as a character
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _pchar(stack_t **stack, unsigned int line_nb)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_nb);
        META.error = 1;
        return;
    }
    
    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_nb);
        META.error = 1;
        return;
    }

    printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _pstr(stack_t **stack, unsigned int line_nb)
{
    stack_t *cur = *stack;
    (void)line_nb;

    while (cur && (cur->n > 0 && cur->n <= 127))
    {
        printf("%c", cur->n);
        cur = cur->next;
    }
    printf("\n");
}

