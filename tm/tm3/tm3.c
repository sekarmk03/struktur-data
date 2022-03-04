#include "header.h"

int main(){
    list L;
    createList(&L); // membuat list L
    char merk[50], tipe[50], jumlah[50]; // deklarasi variabel masukan
    scanf("%s%s%s", merk, tipe, jumlah);
    addFirst(merk, tipe, jumlah, &L); // menambah elemen di awal list L
    scanf("%s%s%s", merk, tipe, jumlah);
    addLast(merk, tipe, jumlah, &L); // menambah elemen di akhir list L
    scanf("%s%s%s", merk, tipe, jumlah);
    addAfter(L.first, merk, tipe, jumlah, &L); // menambah elemen setelah elemen pertama
    printElement(L);
    delAfter(L.data[L.first].next, &L); // menambah elemen setelah L.data[L.first].next
    printElement(L); // mencetak seluruh elemen
    scanf("%s%s%s", merk, tipe, jumlah);
    addAfter(L.data[L.first].next, merk, tipe, jumlah, &L); // menambah elemen setelah L.data[L.first].next
    scanf("%s%s%s", merk, tipe, jumlah);
    addLast(merk, tipe, jumlah, &L); // menambah elemen di akhir
    delFirst(&L); // menghapus elemen pertama
    printElement(L); // mencetak seluruh elemen
    scanf("%s%s%s", merk, tipe, jumlah);
    addFirst(merk, tipe, jumlah, &L); // menambah elemen di awal list L
    delAfter(L.first, &L); // menghapus elemen kedua
    printElementReverse(L); // mencetak seluruh elemen dari belakang
    delAll(&L); // menghapus seluruh elemen
    printElement(L); // mencetak elemen
    printf("========\n");
    return 0;
}