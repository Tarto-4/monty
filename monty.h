#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

typedef struct {
    int array[STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int value, int line_number);
void pall(Stack *stack);

#endif /* MONTY_H */