#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[100];
    int nilai;
} data;

typedef struct smp *alamatsimpul;
typedef struct smp {
    data kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct {
    simpul *root;
} tree;

int i;

void makeTree(data c, tree *T);
void addChild(data c, simpul *root);
void delAll(simpul **root);
// void delChild(data c, simpul *root);
void delChild(simpul *del, simpul *root);
simpul* findSimpul(char cari[], simpul *root);
void printTreePreOrder(simpul *root, simpul *almtRoot);
void printTreePostOrder(simpul *root, simpul *almtRoot);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);