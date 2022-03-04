/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan UAS Soal 2
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// penunjuk alamat simpul dan jalur
typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;

// penamung data
typedef struct {
    char c;
    int visited;
} data;

// representasi simpul
typedef struct smp {
    data kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

// representasi jalur
typedef struct jlr{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul* dest;
} jalur;

// graph
typedef struct {
    simpul* first;
} graph;

// Daftar Prosedur dan Fungsi
void createEmpty(graph *G);
void addSimpul(data c, graph *G);
void addJalur(simpul *awal, simpul *tujuan);
simpul* findSimpul(data c, graph G);
void delJalur(char ctujuan, simpul *awal);
void delAllJalur(simpul *awal);
void delSimpul(data c, graph *G);
void printGraph(graph G);
void cekGraph(graph G, simpul *node);