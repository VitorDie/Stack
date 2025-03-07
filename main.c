#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "stack.h"
#include "node.h"

void clean_stack(stack_t *stack) 
{
    while(stack_size(stack) > 0)
    {
        stack_pop(stack);
    }
}

int main()
{
    stack_t *stack = create_stack();

    stack_push(create_node(1), stack);
    assert(1 == node_get_value(stack_top(stack)));
    assert(1 == stack_size(stack));
    stack_pop(stack);
    assert(stack_size(stack) == 0);
    assert(stack_top(stack) == NULL);

    stack_push(create_node(2), stack);
    stack_push(create_node(3), stack);

    assert(stack_size(stack) == 2);
    assert(3 == node_get_value(stack_top(stack)));

    clean_stack(stack);

    assert(stack_size(stack) == 0);
    assert(stack_top(stack) == NULL);

    free(stack);
    return 0;
}