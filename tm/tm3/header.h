#include <stdio.h>
#include <string.h>

/* Bungkusan Data HP */
typedef struct {
    char merk[50];
    char tipe[50];
    char jumlah[50];
}hp;

/* Bungkusan Elemen List */
typedef struct {
    hp kontainer;
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
void addFirst(char merk[], char tipe[], char jumlah[], list *L); // Menambah elemen di awal
void addAfter(int before, char merk[], char tipe[], char jumlah[], list *L); // Menambah elemen di tengah
void addLast(char merk[], char tipe[], char jumlah[], list *L); // Menambah elemen di akhir
void delFirst(list *L); // Menghapus elemen pertama
void delAfter(int before, list *L); // Menghapus elemen di tengah
void delLast(list *L); // Menghapus elemen terakhir
void delAll(list *L); // Menghapus semua elemen
void printElement(list L); // Mencetak semua elemen
void printElementReverse(list L); // Mencetak semua elemen dari belakang