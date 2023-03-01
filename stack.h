#ifndef C_CORRECTION_STACK_H
#define C_CORRECTION_STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Stack {
    char* word;
    unsigned int size;
};

struct Stack* createEmptyStack();

void push(struct Stack* stack, char word, bool* valid);

char top(struct Stack* stack, bool* valid);

char pop(struct Stack* stack, bool* valid);

unsigned int stackSize(struct Stack* stack);

bool isStackEmpty(struct Stack* stack);

void printStack(struct Stack* stack);

void deleteStack(struct Stack** stack);

#endif //C_CORRECTION_STACK_H
