/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP2
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// data elemen
typedef struct {
    char nama[50];
    int harga;
    int kode;
}dataBarang;

// pointer elemen
typedef struct elmn *alamatElmn;

// elemen
typedef struct elmn {
    dataBarang kontainer;
    alamatElmn prev;
    alamatElmn next;
}elemen;

// list
typedef struct {
    elemen *first;
    elemen *tail;
}list;

// daftar fungsi & prosedur
void createList(list *L);
int countElement(list L);
void addFirst(char nama[], int harga, int kode, list *L);
void addAfter(elemen *before, char nama[], int harga, int kode, list *L);
void addLast(char nama[], int harga, int kode, list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);
void sortList(list *L, char type[], char by);
void swap(elemen *a, elemen *b);