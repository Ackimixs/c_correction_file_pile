#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef C_CORRECTION_LIST_H
#define C_CORRECTION_LIST_H

struct Cell {
    char* word;
    struct Cell* next;
};

struct List {
    unsigned int size;
    struct Cell* head;
};

struct Cell* createCell(char* word);

struct List* createEmptyList();

bool isListEmpty(struct List* list);

unsigned int listSize(struct List* list);

void addFirst(struct List* list, char* word);

void addItemPos(struct List* list, char* word, unsigned int pos, bool* valid);

char* getItemPos(struct List* list, unsigned int pos, bool* valid);

void deleteItemPos(struct List* list, unsigned int pos, bool* valid);

void deleteList(struct List** list);

char* longestWord(struct List* l);

void alphabeticInsert(struct List* l, char* word);

void printList(struct List* l);


#endif //C_CORRECTION_LIST_H