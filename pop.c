#include "monty.h"

/**
 * Initialize a stack.
 */
void initializeStack(Stack *stack) {
    stack->top = -1;
}

/**
 * Check if the stack is empty.
 */
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

/**
 * Check if the stack is full.
 */
int isFull(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

/**
 * Push an element onto the stack.
 */
void push(Stack *stack, int value, int line_number) {
    if (isFull(stack)) {
        fprintf(stderr, "L%d: Error: stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = value;
}

/**
 * Print all values on the stack.
 */
void pall(Stack *stack) {
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }
}