#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list
 *
 * @head: pointer to the head of the doubly linked list
 * @n: the value of the node to add
 * Return: pointer to the new node, NULL on failure
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        META.error = 1;
        return NULL;
    }
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head)
        (*head)->prev = new_node;
    *head = new_node;
    return new_node;
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list
 *
 * @head: pointer to the head of the doubly linked list
 * @n: the value of the node to add
 * Return: pointer to the new node, NULL on failure
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        META.error = 1;
        return NULL;
    }
    new_node->n = n;
    new_node->next = NULL;

    if (!*head)
    {
        new_node->prev = NULL;
        *head = new_node;
        return new_node;
    }

    stack_t *last = *head;
    while (last->next)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
    return new_node;
}

/**
 * _push - adds a value at the top (if in STACK mode)
 * or bottom (if in QUEUE mode) of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 * @a_value: value to add to stack
 */
void _push(stack_t **stack, unsigned int line_nb, char *a_value)
{
    if (!a_value || *a_value == '\0')
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_nb);
        META.error = 1;
        return;
    }

    size_t i = 0;
    while (a_value[i])
    {
        if (!isdigit(a_value[i]) && !(a_value[i] == '-' && i == 0))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_nb);
            META.error = 1;
            return;
        }
        i++;
    }

    int value = atoi(a_value);
    if (META.state == STACK)
        add_dnodeint(stack, value);
    else
        add_dnodeint_end(stack, value);
}

