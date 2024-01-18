#include "monty.h"

void push(Stack *stack, int value, int line_number) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "L%d: Error: malloc failed\n", line_number);
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}