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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    Stack stack;
    initializeStack(&stack);

    char opcode[10];
    int value;
    int line_number = 1;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, value, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "L%d: Error: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(file);

    return 0;
}
