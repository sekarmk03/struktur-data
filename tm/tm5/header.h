#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char nama[50];
    char tahun[50];
}mahasiswa;

typedef struct {
    char pemain[50];
}matkul;

typedef struct eklm *alamatekolom;

typedef struct eklm {
    matkul kontainer_kol;
    alamatekolom next_kol;
}eKolom;

typedef struct ebr *alamatebaris;

typedef struct ebr {
    mahasiswa kontainer;
    eKolom *col;
    alamatebaris next;
}eBaris;

typedef struct {
    eBaris *first;
} list;

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
