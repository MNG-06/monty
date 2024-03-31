#include "monty.h"

/**
 * handle_input - handles the file given as path, and sets fd
 * @argc: the amount of arguments given to the program
 * @argv: the array of arguments given to the program
 * @fp: the file descriptor to set
 *
 * Return: 0 on success, otherwise EXIT_FAILURE
 */
int handle_input(int argc, char **argv, FILE **fp)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    *fp = fopen(argv[1], "r");
    if (*fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }
    return (0);
}

/**
 * handle_line - handles and tokenizes the line read from file
 *
 * @line: the line to tokenize
 *
 * Return: tokens as an array of strings
 */
char **handle_line(char *line)
{
    int i = 0, wc = 0;
    char **args = NULL;
    char *token;

    while (line[i])
    {
        if (!isspace((unsigned char)line[i]))
        {
            wc++;
            while (!isspace((unsigned char)line[i]) && line[i])
                i++;
        }
        else
            i++;
    }

    args = malloc(sizeof(char *) * (wc + 1));
    if (!args)
        return (NULL);

    i = 0;
    token = strtok(line, " \n\t");
    while (token != NULL)
    {
        args[i++] = strdup(token);
        token = strtok(NULL, " \n\t");
    }
    args[i] = NULL;

    return (args);
}

/**
 * free_args - frees the argument tokens array
 *
 * @args: array of tokens
 */
void free_args(char **args)
{
    int i = 0;

    if (args == NULL)
        return;

    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

/**
 * _math - performs all math operations
 *
 * @stack: the program stack
 * @op: operator
 */
void _math(stack_t **stack, char op)
{
    int res = 0;
    stack_t *tmp;

    switch (op)
    {
        case '+':
            res = (*stack)->n + (*stack)->next->n;
            break;
        case '-':
            res = (*stack)->next->n - (*stack)->n;
            break;
        case '/':
            if ((*stack)->n == 0)
                META.error = 1;
            else
                res = (*stack)->next->n / (*stack)->n;
            break;
        case '*':
            res = (*stack)->n * (*stack)->next->n;
            break;
        case '%':
            if ((*stack)->n == 0)
                META.error = 1;
            else
                res = (*stack)->next->n % (*stack)->n;
            break;
    }

    if (META.error == 1)
        return;

    (*stack)->next->n = res;
    tmp = (*stack)->next;
    tmp->prev = NULL;
    free(*stack);
    *stack = tmp;
}

