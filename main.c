#include "Pair.h"
#include "List.h"
#include "stack.h"
#include "Queue.h"

char* compression(char* text) {
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(text);
    char* result = (char*) malloc(len * 2 * sizeof(char));
    while (i < len) {
        count = 1;
        while (text[i] == text[i + 1]) {
            count++;
            i++;
        }
        result[j] = text[i];
        j++;
        char* countStr = (char*) malloc(10 * sizeof(char));

        // use sprintf to convert num to a string and store it in countStr
        sprintf(countStr, "%d", count);
        for (k = 0; k < strlen(countStr); k++) {
            result[j] = countStr[k];
            j++;
        }
        i++;
    }
    result[j] = '\0';
    return result;
}

bool goodCompression(char* text, char* result) {
    int len = strlen(text);
    int len2 = strlen(result);
    return len2 < len;
}

char* decompression(char* text) {
    int i = 0;
    int len = strlen(text);
    int size = 0;

    for (int j = 1; j < len; j += 2) {
        size += atoi(&text[j]);
    }
    char* result = (char*) malloc((size + 1) * sizeof(char));

    for (int j = 0; j < len; j+=2) {
        int count = atoi(&text[j + 1]);
        for (int k = 0; k < count; k++) {
            result[i] = text[j];
            i++;
        }
    }

    result[i] = '\0';
    return result;
}


// Pair
void multiplyOddPairs(struct Pair** pairArray, int n) {
    for (int i = 0; i < n; i++) {
        if (getFirst(pairArray[i]) % 2 == 1)
            setSecond(pairArray[i], getSecond(pairArray[i]) * 3);
    }
}


// List
bool hasLoop(struct List* l) {
    struct Cell* current = l->head;
    while (current != NULL) {
        struct Cell* current2 = current->next;
        while (current2 != NULL) {
            if (current == current2) {
                return true;
            }
            current2 = current2->next;
        }
        current = current->next;
    }
    return false;
}

void reverse(struct List* l) {
    struct Cell* current = l->head;
    struct Cell* previous = NULL;
    struct Cell* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    l->head = previous;
}

// Stack
bool isBalanced(char* word) {
    struct Stack* stack = createEmptyStack();
    int len = strlen(word);
    bool valid = true;
    for (int i = 0; i < len; i++) {
        if (word[i] == '(' || word[i] == '{' || word[i] == '[') {
            push(stack, word[i], &valid);
        } else if (word[i] == ')' || word[i] == '}' || word[i] == ']') {
            if (isStackEmpty(stack)) {
                return false;
            }
            char topChar = top(stack, &valid);
            if (word[i] == ')' && topChar != '(') {
                return false;
            } else if (word[i] == '}' && topChar != '{') {
                return false;
            } else if (word[i] == ']' && topChar != '[') {
                return false;
            }
            pop(stack, &valid);
        }
    }
    return isStackEmpty(stack);
}


// Queue

void josephMethod(int p, int n) {
    struct Queue* queue = createEmptyQueue();
    bool valid = true;
    for (int i = 1; i <= p; i++) {
        enqueue(queue, i, &valid);
    }
    while (!isQueueEmpty(queue)) {
        for (int i = 0; i < n - 1; i++) {
            enqueue(queue, dequeue(queue, &valid), &valid);
        }
        printf("%d ", dequeue(queue, &valid));
    }
    printf("\n");
}

int main() {
/*
   char* text = "aabcccccaaa";

    char* result = compression(text);

    printf("%s\n", result);

    printf("%s\n", goodCompression(text, result) ? "true" : "false");

    printf("%s\n", decompression(result));
*/

/*
    struct List* list = createEmptyList();

    addFirst(list, "!");

    addFirst(list, "world");

    addFirst(list, "hello");

    printList(list);

    reverse(list);

    printList(list);
*/

/*
    char* word = "({[]})";

    printf("%s\n", isBalanced(word) ? "true" : "false"); // true

    printf("%s\n", isBalanced("[()()([][]{[()]})]") ? "true" : "false"); // true

    printf("%s\n", isBalanced("[{()]}") ? "true" : "false"); // false
*/

    josephMethod(13, 2);
    return 0;
}
