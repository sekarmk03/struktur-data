#include "header.h"

int main(){
    list L; // deklarasi list
    createList(&L); // membuat list kosong
    char nama[50], matkul[50], nilai[50]; // deklarasi variabel
    scanf("%s%s%s", nama, matkul, nilai);
    addFirst(nama, matkul, nilai, &L); // menambah elemen di awal
    scanf("%s%s%s", nama, matkul, nilai);
    addAfter(L.first, nama, matkul, nilai, &L); // menambah elemen di posisi kedua
    scanf("%s%s%s", nama, matkul, nilai);
    addBefore(L.first->next, nama, matkul, nilai, &L); // menambah elemen di posisi kedua
    printElement(L); // mencetak seluruh elemen
    delAfter(L.first->next->prev, &L); // menghapus elemen kedua
    scanf("%s%s%s", nama, matkul, nilai);
    addLast(nama, matkul, nilai, &L); // menambah elemen di akhir
    printElement(L); // mencetak seluruh elemen
    delFirst(&L); // menghapus elemen pertama
    scanf("%s%s%s", nama, matkul, nilai);
    addLast(nama, matkul, nilai, &L); // menambah elemen di akhir
    scanf("%s%s%s", nama, matkul, nilai);
    addAfter(L.first->next, nama, matkul, nilai, &L); // menambah elemen di posisi kedua
    delLast(&L); // menghapus elemen terakhir
    printReverse(L); // mencetak seluruh elemen terbalik
    delAll(&L); // menghapus seluruh elemen
    printElement(L); // mencetak seluruh elemen
    return 0;
}