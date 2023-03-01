#include <stdlib.h>

#ifndef C_CORRECTION_PAIR_H
#define C_CORRECTION_PAIR_H

struct Pair {
    int first;
    int second;
};

struct Pair* createPair(int val1, int val2);
int getFirst(struct Pair* pair);
int getSecond(struct Pair* pair);

void setFirst(struct Pair* pair, int val);
void setSecond(struct Pair* pair, int val);

void deletePair(struct Pair* pair);

#endif //C_CORRECTION_PAIR_H
