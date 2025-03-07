#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int size;
    node_t *top;
} stack;

stack_t *create_stack()
{
    stack_t *new_stack = malloc(sizeof(stack_t));

    new_stack->size = 0;
    new_stack->top = NULL;

    return new_stack;
}

int stack_size(stack_t *stack)
{
    return stack->size;
}

void stack_push(node_t *node, stack_t *stack)
{
    if (0 == stack_size(stack))
    {
        stack->top = node;
        stack->size++;
    }
    else
    {
        node_set_next_node(stack_top(stack), node);
        stack->top = node;

        stack->size++;
    }
}

void stack_pop(stack_t *stack)
{
    if (0 == stack_size(stack))
    {
        return;
    }
    else
    {
        node_t *free_it = stack->top;

        stack->top = node_get_next_node(stack_top(stack));
        stack->size--;

        free(free_it);
    }

}

node_t *stack_top(stack_t *stack)
{
    return stack->top;
}