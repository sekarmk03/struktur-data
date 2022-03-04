#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
    char harga[50];
} nilaiMatkul;

typedef struct elmt *alamatelmt;
typedef struct elmt {
    nilaiMatkul kontainer;
    alamatelmt next;
} elemen;

typedef struct {
    elemen *top;
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nama[], char harga[], stack *S);
void pop(stack *S);
void printStack(stack S, char nStack[]);
void popPush(stack *S1, stack *S2);