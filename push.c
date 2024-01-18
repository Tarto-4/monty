#include "monty.h"

void push(Stack *stack, int value, int line_number)
{
    if (stack->top == STACK_SIZE - 1)
    {
        fprintf(stderr, "L%d: Error: stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = value;
}