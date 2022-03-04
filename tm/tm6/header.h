#include <stdio.h>
#include <malloc.h>
#include <string.h>

// penampung data baris
typedef struct {
    char nama[50];
    char tahun[50];
}mahasiswa;

// penampung data kolom
typedef struct {
    char pemain[50];
}matkul;

// alamat elemen kolom
typedef struct eklm *alamatekolom;

// elemen kolom
typedef struct eklm {
    matkul kontainer_kol;
    alamatekolom next_kol;
}eKolom;

// alamat elemen baris
typedef struct ebr *alamatebaris;

// elemen baris
typedef struct ebr {
    mahasiswa kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

// list
typedef struct {
    eBaris *first;
}list;

/* Prosedur dan Fungsi */
void createList(list *L);
int countElementB (list L);
int countElementK(eBaris L);
void addFirstB(char nama[], char tahun[], list *L);
void addFirstK(char pemain[], eBaris *L);
void addAfterB(eBaris* prev, char nama[], char tahun[], list *L);
void addAfterK(eKolom* prev, char pemain[]);
void addLastB(char nama[], char tahun[], list *L);
void addLastK(char pemain[], eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom* prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris* prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
eBaris *sortDinamyc(list *L2, char nama[], char tahun[]);
void sortList(list *L);
void swap(eBaris *a, eBaris *b);