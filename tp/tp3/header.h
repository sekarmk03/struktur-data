/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan TP3
    dalam mata kuliah Struktur Data 1 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

/* Struct Data Playlist */
typedef struct {
    char tahun[50];
    char judul[50];
    char band[50];
} playlist;

/* Pointer Struct Lengan Penghubung */
typedef struct elmt *alamatelmt;

/* Elemen Stack */
typedef struct elmt {
    playlist kontainer;
    alamatelmt next;
} elemen;

/* Stack */
typedef struct {
    elemen *top;
} stack;

/* Fungsi dan Prosedur */
void createEmpty(stack *S); // membuat stack kosong
int isEmpty(stack S); // mengecek apakah stack kosong
int countElement(stack S); // menghitung elemen stack
void push(char tahun[], char judul[], char band[], stack *S); // memasukkan data ke stack
void pop(stack *S); // menghapus data dari stack
void printStack(stack S, int stackNo); // mencetak isi stack
int countAscii(char str[]); // menghitung nilai ascii judul lagu
void musicPlaylist(stack *S1, stack *S2, stack *S3); // memasukkan lagu ke playlist yg sesuai