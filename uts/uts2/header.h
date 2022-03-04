/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan soal UTS
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// penyimpan data restoran (baris)
typedef struct {
    char nama[100];
    char menuSwitch[100];
} restoran;

// penyimpan data menu (kolom)
typedef struct {
    char menu[100];
    int harga;
} menuRestoran;

// alamat kolom
typedef struct eklm *alamatekolom;

// elemen kolom
typedef struct eklm {
    menuRestoran kontainer_kol;
    alamatekolom next_kol;
} eKolom;

// alamat baris
typedef struct ebr *alamtebaris;

// elemen baris
typedef struct ebr {
    restoran kontainer;
    eKolom *col;
    alamtebaris next;
} eBaris;

// list
typedef struct {
    eBaris *first;
} list;

/* Prosedur dan Fungsi */
void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(restoran Resto, list *L);
void addFirstK(menuRestoran Menu,  eBaris *L);
void addAfterB(eBaris *prev, restoran Resto, list *L);
void addAfterK(eKolom *prev, menuRestoran Menu) ;
void addLastB(restoran Resto, list *L);
void addLastK(menuRestoran Menu,  eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
eBaris *getBaris(list L, char nama[]);
eKolom* getLastKolom(eBaris *L);
void switchMenu(restoran restoA, restoran restoB, list *L);