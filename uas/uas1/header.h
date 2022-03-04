/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan UAS Soal 1
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// tampungan data
typedef struct {
    int kiri, kanan;
}data;

// alamat simpul tree
typedef struct smp *alamatsimpul;

// simpul tree
typedef struct smp {
    data kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

// tree
typedef struct{
    simpul *root;
} tree;

int tampungOutput[100], Idx;

// prosedur dan fungsi
void makeTree(data c, tree *T);
void addRight(int kiri, int kanan, simpul *root);
void addLeft(int kiri, int kanan, simpul *root);
void delAll(simpul *root);
void delRight(simpul *root);
void delLeft(simpul *root);
void printTreePreOrder(simpul *root, simpul *almtRoot);
void printTreeInOrder(simpul *root);
void printTreePostOrder(simpul *root, simpul *almtRoot);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
void addData(int kiri, int kanan, simpul *root);