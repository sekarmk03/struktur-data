/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP5
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

typedef struct {
    char nama[100];
    int korban;
    int level;
} data;

// alamat simpul/node
typedef struct smp *alamatsimpul;

// simpul/node
typedef struct smp {
    data daerah; // data dlm simpul
    alamatsimpul sibling; // penunjuk saudara
    alamatsimpul child; // penunjuk anak
} simpul;

// tree
typedef struct {
    simpul *root;
} tree;

// int jumlah;
// int level;

// Prosedur dan Fungsi
void makeTree(data d, tree *T); // membuat tree
void addChild(data d, simpul *root); // menambah anak
void delAll(simpul **root); // menghapus seluruh tree
void delChild(simpul *del, simpul *root); // menghapus anak
simpul* findSimpul(char cari[], simpul *root); // mencari node
void printTreePreOrder(simpul *root, int n, int len[]); // mencetak node
void printTreePostOrder(simpul *root, simpul *almtRoot); // mencetak node
void copyTree(simpul *root1, simpul **root2); // menyalin tree
int isEqual(simpul *root1, simpul *root2); // mengecek kesamaan dua buah tree
void explode(char str[], char first[], char second[], int *num, char splitter);
int hitungKorban(simpul *root, simpul *almtRoot);
void maxLenName(simpul *root, int n, int len[]);
int totalDigit(int num);