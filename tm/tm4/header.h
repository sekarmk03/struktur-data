#include <stdio.h>
#include <string.h>
#include <malloc.h>

// data elemen
typedef struct {
    char nama[50];
    char matkul[50];
    char nilai[50];
}nilaiMatkul;

// pointer elemen
typedef struct elmn *alamatElmn;

// elemen
typedef struct elmn {
    nilaiMatkul kontainer;
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
void addFirst(char nama[], char matkul[], char nilai[], list *L);
void addAfter(elemen *before, char nama[], char matkul[], char nilai[], list *L);
void addLast(char nama[], char matkul[], char nilai[], list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);
void printElement(list L);
void addBefore(elemen *after, char nama[], char matkul[], char nilai[], list *L);
void printReverse(list L);