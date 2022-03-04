/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP4
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Struct Penampung Data Pengantri
typedef struct {
    char nama[100];
    int priority;
    int waktu;
} dtPengantri;

// Penunjuk Alamat
typedef struct elm *alamatelmt;

// Elemen
typedef struct elm {
    dtPengantri kontainer;
    alamatelmt next;
} elemen;

// Queue
typedef struct {
    elemen *first;
    elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(dtPengantri pengantri, queue *Q);
void addPriority(dtPengantri pengantri, queue *Q);
void del(queue *Q1);
void pindahQueue(queue *Q1);
void printQueue(queue Q);