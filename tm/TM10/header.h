#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

typedef struct smp {
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul* dest;
} jalur;

typedef struct {
    simpul* first;
} graph;

void createEmpty(graph *G);
void addSimpul(int c, graph *G);
void addJalur(simpul *awal, simpul *tujuan);
simpul* findSimpul(int c, graph G);
void delJalur(int ctujuan, simpul *awal);
void delAllJalur(simpul *awal);
void delSimpul(int c, graph *G);
void printGraph(graph G);
