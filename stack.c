#include "stack.h"

struct Stack* createEmptyStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->word = (char*) malloc(sizeof(char));
    stack->size = 0;
    return stack;
}

void push(struct Stack* stack, char word, bool* valid) {
    stack->word = (char*) realloc(stack->word, (stack->size + 1) * sizeof(char));
    stack->word[stack->size] = word;
    stack->size++;
    *valid = true;
}

char top(struct Stack* stack, bool* valid) {
    if (stack->size == 0) {
        *valid = false;
        return '\0';
    }
    *valid = true;
    return stack->word[stack->size - 1];
}

char pop(struct Stack* stack, bool* valid) {
    if (stack->size == 0) {
        *valid = false;
        return '\0';
    }
    char word = stack->word[stack->size - 1];
    stack->word = (char*) realloc(stack->word, (stack->size - 1) * sizeof(char));
    stack->size--;
    *valid = true;
    return word;
}

unsigned int stackSize(struct Stack* stack) {
    return stack->size;
}

bool isStackEmpty(struct Stack* stack) {
    return stack->size == 0;
}

void printStack(struct Stack* stack) {
    for (int i = stack->size - 1; i >= 0; i--) {
        printf("%c", stack->word[i]);
    }
    printf("\n");
}

void deleteStack(struct Stack** stack) {
    free((*stack)->word);
    free(*stack);
    *stack = NULL;
}