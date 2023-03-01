#include "Pair.h"

struct Pair* createPair(int val1, int val2) {
    struct Pair* pair = (struct Pair*) malloc(sizeof(struct Pair));
    pair->first = val1;
    pair->second = val2;
    return pair;
}

int getFirst(struct Pair* pair) {
    return pair->first;
}

int getSecond(struct Pair* pair) {
    return pair->second;
}

void setFirst(struct Pair* pair, int val) {
    pair->first = val;
}

void setSecond(struct Pair* pair, int val) {
    pair->second = val;
}

void deletePair(struct Pair* pair) {
    free(pair);
}