#include "monty.h"

void add(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int operand1 = pop(stack, line_number);
    int operand2 = pop(stack, line_number);
    push(stack, operand1 + operand2, line_number);
}

void sub(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int operand1 = pop(stack, line_number);
    int operand2 = pop(stack, line_number);
    push(stack, operand2 - operand1, line_number);
}

void mul(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int operand1 = pop(stack, line_number);
    int operand2 = pop(stack, line_number);
    push(stack, operand1 * operand2, line_number);
}

void division(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int operand1 = pop(stack, line_number);
    int operand2 = pop(stack, line_number);
    if (operand1 == 0) {
        fprintf(stderr, "L%d: Error: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    push(stack, operand2 / operand1, line_number);
}

void mod(Stack *stack, int line_number) {
    if (stack->top < 1) {
        fprintf(stderr, "L%d: Error: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int operand1 = pop(stack, line_number);
    int operand2 = pop(stack, line_number);
    if (operand1 == 0) {
        fprintf(stderr, "L%d: Error: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
    push(stack, operand2 % operand1, line_number);
}