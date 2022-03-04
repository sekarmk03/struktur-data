#include <stdio.h>
#include <malloc.h>
#include <string.h>

// struct penampung data senyawa
typedef struct {
    float flo;
}data;

// struct pointer
typedef struct pointEl* elAddress;

// struct elemen
typedef struct pointEl {
    data container;
    elAddress next;
}element;

// list
typedef struct {
    element* first;
}list;

/* deklarasi prosedur dan fungsi */
void createList(list *L); // membuat list (pointer first)
int countElement(list L); // menghitung jumlah elemen dlm list
void addFirst(float flo, list *L); // menambah 1 elemen di awal list
void addAfter(element* prev, float flo, list *L); // menambah 1 elemen setelah elemen tertentu
void addLast(float flo, list *L); // menambah 1 elemen di akhir list
void delFirst(list *L); // menghapus 1 elemen di awal list
void delAfter(element *prev, list *L); // menghapus 1 elemen setelah elemen tertentu
void delLast(list *L); // menghapus 1 elemen di akhir list
void delAll(list *L); // menghapus seluruh elemen list
void printElement(list L); // mencetak seluruh elemen list
void addArange(float flo, list *L);