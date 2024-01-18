#include "monty.h"

/**
* f_push - function that adds node to the stack
* @stack: double head pointer to the stack
* @line_number: line count
* @value: intt value
* Return: nothing
*/

void push(Stack *stack, int value, int line_number)
{
    if (stack->top == STACK_SIZE - 1)
    {
        fprintf(stderr, "L%d: Error: stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = value;
}