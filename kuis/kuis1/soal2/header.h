/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Kuis 1 Soal 1
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

/* Bungkusan Data katakata */
typedef struct {
    char kata[100];
}katakata;

/* Bungkusan Elemen List */
typedef struct {
    katakata kontainer;
    int prev;
    int next;
}elemen;

/* Bungkusan List */
typedef struct {
    int first;
    int tail;
    elemen data[20];
}list;

/* Deklarasi Prosedur dan Fungsi */
void createList(list *L); // Membuat kerangka list
int countElement(list L); // Menghitung elemen list
int emptyElement(list L); // Menegecek elemen yg kosong
void addFirst(char kata[], list *L); // Menambah elemen di awal
void addAfter(int before, char kata[], list *L); // Menambah elemen di tengah
void addLast(char kata[], list *L); // Menambah elemen di akhir
void delFirst(list *L); // Menghapus elemen pertama
void delAfter(int before, list *L); // Menghapus elemen di tengah
void delLast(list *L); // Menghapus elemen terakhir
void delAll(list *L); // Menghapus semua elemen
void printElement(list L, int n); // Mencetak semua elemen
void printElementReverse(list L); // Mencetak semua elemen dari belakang