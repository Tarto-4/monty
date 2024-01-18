#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initializeStack(Stack *stack);
int isEmpty(Stack *stack);
void push(Stack *stack, int value, int line_number);
void pall(Stack *stack);

#endif /* MONTY_H */