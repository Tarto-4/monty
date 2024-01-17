#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value, int line_number) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    stack[++top] = value;
}

// Function to print all values on the stack
void pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

return 0;