#include "monty.h"
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    Stack stack;
    initializeStack(&stack);

    char opcode[10];
    int value, line_number = 0;

    while (fscanf(file, "%s", opcode) != EOF)
    {
        line_number++;
        OpcodeType opcodeType = getOpcodeType(opcode);

        // Check the opcode type and perform the corresponding operation
        switch (opcodeType)
        {
            case PUSH:
            if (fscanf(file, "%d", &value) != 1)
            {
                fprintf(stderr, "L%d: Error: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, value, line_number);
            break;
            case POP:
            pop(&stack, line_number);
            break;
            case PALL:
            pall(&stack);
            break;
            case ADD:
            add(&stack, line_number);
            break;
            case SUB:
            sub(&stack, line_number);
            break;
            case MUL:
            mul(&stack, line_number);
            break;
            case DIV:
            division(&stack, line_number);
            break;
            case MOD:
            mod(&stack, line_number);
            break;
            case SWAP:
            swap(&stack, line_number);
            break;
            case ROTL:
            rotl(&stack, line_number);
            break;
            case ROTR:
            rotr(&stack, line_number);
            break;
            case NULL_OPCODE:
            fprintf(stderr, "L%d: Error: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
            break;
        }
    }
    fclose(file);
    return 0;
}

OpcodeType getOpcodeType(const char *opcode)
{
    if (strcmp(opcode, "push") == 0)
    {
        return PUSH;
    } else if (strcmp(opcode, "pop") == 0)
    {
        return POP;
    } else if (strcmp(opcode, "pall") == 0)
    {
        return PALL;
    } else if (strcmp(opcode, "add") == 0)
    {
        return ADD;
    } else if (strcmp(opcode, "sub") == 0)
    {
        return SUB;
    } else if (strcmp(opcode, "mul") == 0)
    {
        return MUL;
    } else if (strcmp(opcode, "div") == 0)
    {
        return DIV;
    } else if (strcmp(opcode, "mod") == 0)
    {
        return MOD;
    } else if (strcmp(opcode, "swap") == 0)
    {
        return SWAP;
    } else if (strcmp(opcode, "rotl") == 0)
    {
        return ROTL;
    } else if (strcmp(opcode, "rotr") == 0) 
    {
        return ROTR;
    } else
    {
        return NULL_OPCODE;
    }
}