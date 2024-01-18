#include "monty.h"

/**
* swap - function that swaps the top two elements of the stack
* @stack: head of stack
* @line_number: line count
*
* Return: nothing
*/

void swap(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int temp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = temp;
}

void rotr(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't rotr, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int temp = stack->array[stack->top];
    for (int i = stack->top; i > 0; i--) {
        stack->array[i] = stack->array[i - 1];
    }
    stack->array[0] = temp;
}

void rotl(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't rotl, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int temp = stack->array[0];
    for (int i = 0; i < stack->top; i++) {
        stack->array[i] = stack->array[i + 1];
    }
    stack->array[stack->top] = temp;
}