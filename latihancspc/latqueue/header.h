#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    char nama[100];
    char ktp[100];
} nilaiMatkul;

typedef struct elm *alamatelmt;

typedef struct elm {
    nilaiMatkul kontainer;
    alamatelmt next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], char ktp[], queue *Q);
void addPriority(char nama[], char ktp[], int priority, queue *Q);
void del(queue *Q1);
void printQueue(queue *Q, int n, int Queue);