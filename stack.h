#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct stack stack_t;
stack_t *create_stack();
int stack_size(stack_t *stack);
void stack_push(node_t *node, stack_t *stack);
void stack_pop(stack_t *stack);
node_t *stack_top(stack_t *stack);

#endif