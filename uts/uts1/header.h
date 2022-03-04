#include <stdio.h>
#include <malloc.h>
#include <string.h>

// penampung data baris
typedef struct {
    char nama[200], menuSwitch[200];
}restoran;

// penampung data kolom
typedef struct {
    char menu[200], harga[200];
}menuRestoran;

// alamat elemen kolom
typedef struct eklm *alamatekolom;

// elemen kolom
typedef struct eklm {
    menuRestoran kontainer_kol;
    alamatekolom next_kol;
}eKolom;

// alamat elemen baris
typedef struct ebr *alamatebaris;

// elemen baris
typedef struct ebr {
    restoran kontainer;
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
void addFirstB(char nama[], list *L);
void addFirstK(char menu[], char harga[], eBaris *L);
void addAfterB(eBaris* prev, char nama[], list *L);
void addAfterK(eKolom* prev, char menu[], char harga[]);
void addLastB(char nama[], list *L);
void addLastK(char menu[], char harga[], eBaris *L);
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
eBaris* getLatestBaris(list L, char nama[]);
void SwitchMenu(char resto1[], char menu[], char resto2[], list *L);
eKolom* getLastKolom(eBaris *L);
eBaris* getBaris(list *L, char resto[]);
eKolom* getKolom(eBaris *L, char menu[]);
eBaris *tunjukBaris(list L, char nama[]);
void switchMenu(restoran masukanDari, restoran masukanKe, list *L);