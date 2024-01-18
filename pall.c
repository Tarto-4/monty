#include "monty.h"

void pall(Stack *stack) {
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}