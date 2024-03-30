#include "monty.h"

/**
 * _pop - deletes the node at the top of the stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _pop(stack_t **stack, unsigned int line_nb) {
    if (!stack || !*stack) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_nb);
        META.error = 1;
        return;
    }

    stack_t *tmp = *stack;
    *stack = (*stack)->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(tmp);
}

/**
 * _swap - swaps the first two at the top of the stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _swap(stack_t **stack, unsigned int line_nb) {
    if (!stack || !*stack || !(*stack)->next) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_nb);
        META.error = 1;
        return;
    }

    int tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
}
