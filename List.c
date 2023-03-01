#include "List.h"

struct Cell* createCell(char* word) {
    struct Cell* cell = (struct Cell*) malloc(sizeof(struct Cell));
    cell->word = word;
    cell->next = NULL;
    return cell;
}

struct List* createEmptyList() {
    struct List* list = (struct List*) malloc(sizeof(struct List));
    list->size = 0;
    list->head = NULL;
    return list;
}

bool isListEmpty(struct List* list) {
    return list->size == 0;
}

unsigned int listSize(struct List* list) {
    return list->size;
}

void addFirst(struct List* list, char* word) {
    struct Cell* cell = createCell(word);
    cell->next = list->head;
    list->head = cell;
    list->size++;
}

void addItemPos(struct List* list, char* word, unsigned int pos, bool* valid) {
    if (pos > list->size) {
        *valid = false;
        return;
    }
    struct Cell* cell = createCell(word);
    if (pos == 0) {
        cell->next = list->head;
        list->head = cell;
    } else {
        struct Cell* current = list->head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        cell->next = current->next;
        current->next = cell;
    }
    list->size++;
    *valid = true;
}

char* getItemPos(struct List* list, unsigned int pos, bool* valid) {
    if (pos >= list->size) {
        *valid = false;
        return NULL;
    }
    struct Cell* current = list->head;
    for (int i = 0; i < pos; i++) {
        current = current->next;
    }
    *valid = true;
    return current->word;
}

void deleteItemPos(struct List* list, unsigned int pos, bool* valid) {
    if (pos >= list->size) {
        *valid = false;
        return;
    }
    struct Cell* current = list->head;
    if (pos == 0) {
        list->head = current->next;
    } else {
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        struct Cell* toDelete = current->next;
        current->next = toDelete->next;
        free(toDelete);
    }
    list->size--;
    *valid = true;
}

void deleteList(struct List** list) {
    struct Cell* current = (*list)->head;
    while (current != NULL) {
        struct Cell* toDelete = current;
        current = current->next;
        free(toDelete);
    }
    free((*list));
}

char* longestWord(struct List* l) {
    if (isListEmpty(l)) {
        return NULL;
    }
    struct Cell* current = l->head;
    char* longest = current->word;
    while (current != NULL) {
        if (strlen(current->word) > strlen(longest)) {
            longest = current->word;
        }
        current = current->next;
    }
    return longest;
}

void alphabeticInsert(struct List* l, char* word) {
    if (isListEmpty(l)) {
        addFirst(l, word);
        return;
    }
    struct Cell* current = l->head;
    if (strcmp(word, current->word) < 0) {
        addFirst(l, word);
        return;
    }
    while (current->next != NULL) {
        if (strcmp(word, current->next->word) < 0) {
            struct Cell* cell = createCell(word);
            cell->next = current->next;
            current->next = cell;
            l->size++;
            return;
        }
        current = current->next;
    }
    addFirst(l, word);
}

void printList(struct List* l) {
    struct Cell *current = l->head;
    while (current != NULL) {
        printf("%s, ", current->word);
        current = current->next;
    }
    printf("\n");
}