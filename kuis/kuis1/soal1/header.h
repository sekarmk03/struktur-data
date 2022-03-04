/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Kuis 1 Soal 2
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// struct penampung data makanan
typedef struct {
    char food[50];
    char harga[50];
}menu;

// struct pointer
typedef struct pointEl* elAddress;

// struct elemen
typedef struct pointEl {
    menu container;
    elAddress next;
}element;

// list
typedef struct {
    element* first;
}list;

/* deklarasi prosedur dan fungsi */
void createList(list *L); // membuat list (pointer first)
int countElement(list L); // menghitung jumlah elemen dlm list
void addFirst(char food[], char harga[], list *L); // menambah 1 elemen di awal list
void addAfter(element* prev, char food[], char harga[], list *L); // menambah 1 elemen setelah elemen tertentu
void addLast(char food[], char harga[], list *L); // menambah 1 elemen di akhir list
void delFirst(list *L); // menghapus 1 elemen di awal list
void delAfter(element *prev, list *L); // menghapus 1 elemen setelah elemen tertentu
void delLast(list *L); // menghapus 1 elemen di akhir list
void delAll(list *L); // menghapus seluruh elemen list
void printElement(list L); // mencetak seluruh elemen list
void swap(element *a, element *b); // menukar elemen
void sortList(list *L, char type[]); // mengurutkan elemen
void swapMenu(list *K, list *L, list *M);
void tukarMenu(list *K, list *L, list *M);