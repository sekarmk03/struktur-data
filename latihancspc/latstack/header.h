#include <stdio.h>
#include <string.h>

typedef struct {
    int index;
    char tanda;
} nilaiMatkul;

typedef struct {
    int top;
    nilaiMatkul data[100];
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(int index, char tanda, stack *S);
void pop(stack *S);
void printStack(stack S);
void moveElStack(stack *S1, stack *S2);
void cekPair(int index, char tanda, stack *S);