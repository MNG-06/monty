#include "monty.h"

/**
 * _check_stack_short - checks if the stack is too short
 *
 * @stack: the program stack
 * @line_nb: the line number
 * @operation: string representing the operation being performed
 * @error_code: the error code to set if the stack is too short
 */
static void _check_stack_short(stack_t **stack, unsigned int line_nb, const char *operation, int error_code)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_nb, operation);
		META.error = error_code;
	}
}

/**
 * _add - addition of the first two values at top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _add(stack_t **stack, unsigned int line_nb)
{
	_check_stack_short(stack, line_nb, "add", 1);
	if (!META.error)
		_math(stack, '+');
}

/**
 * _sub - subtraction of top of stack from 2nd top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _sub(stack_t **stack, unsigned int line_nb)
{
	_check_stack_short(stack, line_nb, "sub", 1);
	if (!META.error)
		_math(stack, '-');
}

/**
 * _div - division of second top of stack by top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _div(stack_t **stack, unsigned int line_nb)
{
	_check_stack_short(stack, line_nb, "div", 1);
	if (!META.error)
	{
		_math(stack, '/');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_nb);
	}
}

/**
 * _mul - multiplication of the two values at top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _mul(stack_t **stack, unsigned int line_nb)
{
	_check_stack_short(stack, line_nb, "mul", 1);
	if (!META.error)
		_math(stack, '*');
}

/**
 * _mod - modulo of second top of stack by top of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 */
void _mod(stack_t **stack, unsigned int line_nb)
{
	_check_stack_short(stack, line_nb, "mod", 1);
	if (!META.error)
	{
		_math(stack, '%');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_nb);
	}
}
