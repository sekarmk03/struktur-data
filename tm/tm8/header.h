#include <stdio.h>
#include <malloc.h>
#include <string.h>

// alamat simpul tree
typedef struct smp *alamatsimpul;

// simpul tree
typedef struct smp {
    char kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

// tree
typedef struct{
    simpul *root;
} tree;

// prosedur dan fungsi
void makeTree(char c, tree *T);
void addRight(char c, simpul *root);
void addLeft(char c, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root, simpul *almtRoot);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root, simpul *almtRoot);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
