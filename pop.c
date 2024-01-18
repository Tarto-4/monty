#include "monty.h"

int pop(Stack *stack, int line_number) {
    if (stack->top == -1) {
        fprintf(stderr, "L%d: Error: cannot pop from an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}