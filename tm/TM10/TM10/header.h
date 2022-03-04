#include <stdio.h>
#include <malloc.h>
//menginisialisasikan tipe data terstruktur dari alamat simpul
typedef struct smp *alamatsimpul;
//menginisialisasikan tipe data terstruktur dari alamat jalur
typedef struct jlr *alamatjalur;
//membuat tipe data tersetruktur untuk menampung simpul
typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;
//membuat tipe data tersetruktur untuk menampung jalur
typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;
//membuat tipe data tersetruktur untuk menampung graph
typedef struct
{
    simpul *first;
} graph;
/* 
**create = prosedur untuk membuat root dari Graph 
**addSimpul, addJalur = prosedur untuk menambahkan node dan jalur pada Graph 
**deAll, delJalur, delSimpul = prosedur untuk menghapus semua node, node jalur dan node 
**printGraph = prosedur untuk menampilkan Graph  
**findSimpul = fungsi untuk mendapatkan simpul 
 */
void createEmpty(graph *G);
void addSimpul(int c, graph *G);
void addJalur(simpul *awal, simpul *tujuan, int beban);
simpul *findSimpul(int c, graph G);
void delJalur(int ctujuan, simpul *awal);
void delAll(simpul *awal);
void delSimpul(int c, graph *G);
void printGraph(graph G);