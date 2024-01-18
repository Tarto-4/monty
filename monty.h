#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

// Structure representing a stack
typedef struct {
    int array[STACK_SIZE];
    int top;
} Stack;

// Enumeration for different opcode types
typedef enum {
    PUSH,
    POP,
    PALL,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    SWAP,
    ROTL,
    ROTR,
    NULL_OPCODE,  // Placeholder for unknown opcodes
} OpcodeType;

// Function to initialize the stack
void initializeStack(Stack *stack);

// Function to push an element onto the stack
void push(Stack *stack, int value, int line_number);

// Function to pop an element from the stack
int pop(Stack *stack, int line_number);

// Function to print all values on the stack
void pall(Stack *stack);

// Function to perform addition
void add(Stack *stack, int line_number);

// Function to perform subtraction
void sub(Stack *stack, int line_number);

// Function to perform multiplication
void mul(Stack *stack, int line_number);

// Function to perform division
void division(Stack *stack, int line_number);

// Function to perform modulo operation
void mod(Stack *stack, int line_number);

// Function to swap the top two elements of the stack
void swap(Stack *stack, int line_number);

// Function to rotate the stack to the top (move the top element to the bottom)
void rotr(Stack *stack, int line_number);

// Function to rotate the stack to the bottom (move the bottom element to the top)
void rotl(Stack *stack, int line_number);

// Function to identify the opcode type
OpcodeType getOpcodeType(const char *opcode);

#endif /* MONTY_H */