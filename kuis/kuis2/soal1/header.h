/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Kuis 2 Soal 1
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

// penampung data
typedef struct {
    char nama[100];
    char bahan[100];
} baju;

// stack
typedef struct {
    int top;
    baju data[100];
} stack;

// fungsi dan prosedur
void createEmpty(stack *S); // Prosedur Membuat Stack
int isEmpty(stack S); // Fungsi Mengecek Apakah Stack Kosong
int isFull(stack S); // Fungsi Mengecek Apakah Stack Penuh
void push(char nama[], char bahan[], stack *S); // Prosedur Menambah Elemen ke Stack
void pop(stack *S); // Prosedur Menghapus Elemen Stack
void printStack(stack S, int flag); // Prosedur Mencetak Elemen Stack
void popPush(stack *S1, stack *S2); // Prosedur Memindahkan Elemen Stack
int cariBahan(stack *S1, char cari[][100], int n); // Fungsi Mencari Bahan Pakaian
void pindahBahan(stack *S1, stack *S2, int idxMin); // Prosedur Memindahkan Bahan-bahan