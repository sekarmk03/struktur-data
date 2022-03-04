#include <stdio.h>
#include <string.h>

#define n 50 // jumlah data maksimal

/* Struct Container
   Bungkusan data inventory */
typedef struct {
    char merk[30], warna[30];
    int ukuran;
}container;

/* Struct Element
   Bungkusan elemen list */
typedef struct {
    container inventory;
    int next;
}element;

/* Struct List
   Representasi list */
typedef struct {
    element data[50];
    int first;
}list;

/* Daftar prosedur & fungsi */
void createList(list *L); // membuat list
int countElement(list L); // menghitung elemen list
int emptyElement(list L); // mencari elemen kosong
void addFirst(char merk[30], char warna[30], int ukuran, list *L); // menambah elemen di awal
void addAfter(int prev, char merk[30], char warna[30], int ukuran, list *L); // menambah elemen setelah elemen tertentu
void addLast(char merk[30], char warna[30], int ukuran, list *L); // menambah element di akhir
void delFirst(list *L); // menghapus elemen pertama
void delAfter(int prev, list *L); // menghapus elemen setelah elemen tertentu
void delLast(list *L); // menghapus elemen terakhir
void delAll(list *L); // menghapus seluruh elemen
void printElement(list L); // mencetak isi list