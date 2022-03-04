/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP5
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// alamat simpul/node
typedef struct smp *alamatsimpul;

// simpul/node
typedef struct smp {
    char nama[100]; // data dlm simpul
    alamatsimpul sibling; // penunjuk saudara
    alamatsimpul child; // penunjuk anak
} simpul;

// tree
typedef struct {
    simpul *root;
} tree;

// Prosedur dan Fungsi
void makeTree(char nama[], tree *T); // membuat tree
void addChild(char nama[], simpul *root); // menambah anak
void delAll(simpul **root); // menghapus seluruh tree
void delChild(simpul *del, simpul *root); // menghapus anak
simpul* findSimpul(char cari[], simpul *root); // mencari node
void printTreePreOrder(simpul *root, int n, int prt); // mencetak node
void printTreePostOrder(simpul *root, simpul *almtRoot); // mencetak node
void copyTree(simpul *root1, simpul **root2); // menyalin tree
int isEqual(simpul *root1, simpul *root2); // mengecek kesamaan dua buah tree