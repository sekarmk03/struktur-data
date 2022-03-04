/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Tugas Masa Depan (TMD)
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/* Library */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

// struct penampung data pada simpul tree
typedef struct {
    char nama[100]; // nama daerah
    int korban; // jumlah korban
} data;

// alamat simpul/node
typedef struct smp *alamatsimpul;

// simpul/node
typedef struct smp {
    data daerah; // data dalam simpul
    alamatsimpul sibling; // penunjuk saudara
    alamatsimpul child; // penunjuk anak
} simpul;

// tree
typedef struct {
    simpul *root;
} tree;

// Prosedur dan Fungsi
void makeTree(data d, tree *T); // membuat tree
void addChild(data d, simpul *root); // menambah anak
simpul* findSimpul(char cari[], simpul *root); // mencari node
void printTreePreOrder(simpul *root, int n, int len[]); // mencetak tree
void explode(char str[], char first[], char second[], int *num, char splitter); // memecah string
int hitungKorban(simpul *root); // menghitung jumlah korban
void maxLenName(simpul *root, int n, int len[]); // mencari nama daerah terpanjang
int totalDigit(int num); // menghitung jumlah digit