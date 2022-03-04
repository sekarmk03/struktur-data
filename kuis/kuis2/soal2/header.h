/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Kuis 2 Soal 2
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// data sumbangan
typedef struct {
    char nama[100];
    char alamat[100];
    char dana[100];
    int priority;
} sumbangan;

// alamat element
typedef struct elm *alamatelmt;

// elemen
typedef struct elm {
    sumbangan kontainer;
    alamatelmt next;
} elemen;

// queue
typedef struct {
    elemen *first;
    elemen *last;
} queue;

// fungsi dan prosedur
void createEmpty(queue *Q); // membuat queue
int isEmpty(queue Q); // mengecek apakah queue kosong
int countElement(queue Q); // menghitung elemen queue
void add(char nama[], char alamat[], char dana[], int priority, queue *Q); // menambah elemen ke queue
void addPriority(char nama[], char alamat[], char dana[], int priority, queue *Q); // menambah elemen dengan prioritas
void del(queue *Q1); // menghapus elemen
void printQueue(queue *Q, int n, int Queue); // mencetak elemen