#include "monty.h"

void initializeStack(Stack *stack) {
    stack->top = NULL;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

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

void pall(Stack *stack) {
    Node *current = stack->top;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
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
    int line_number = 0;

    while (fscanf(file, "%s", opcode) != EOF) {
        line_number++;
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
    }

    fclose(file);

    // Free allocated memory
    while (!isEmpty(&stack)) {
        Node *temp = stack.top;
        stack.top = stack.top->next;
        free(temp);
    }

    return 0;
}