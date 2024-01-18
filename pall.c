#include "monty.h"

/**
* pall - function that prints everything in the stack
* @stack: double head pointer to the stack
* Return: nothing
*/

void pall(Stack *stack)
{
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->array[i]);
    }
}