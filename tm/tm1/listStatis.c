#include "header.h"

int main() {
    list L;
    // buat list
    createList(&L);
    char merk[30], warna[30];
    int ukuran = 0;
    // menambah elemen di awal list
    scanf("%s%s%d", merk, warna, &ukuran);
    addFirst(merk, warna, ukuran, &L);

    // menambah elemen di awal list
    scanf("%s%s%d", merk, warna, &ukuran);
    addFirst(merk, warna, ukuran, &L);

    // menambah elemen di akhir list
    scanf("%s%s%d", merk, warna, &ukuran);
    addLast(merk, warna, ukuran, &L);

    // mencetak seluruh isi list
    printElement(L);

    // menghapus elemen terakhir
    delLast(&L);

    // menambah elemen di akhir list
    scanf("%s%s%d", merk, warna, &ukuran);
    addLast(merk, warna, ukuran, &L);

    // menambah elemen setelah elemen pertama
    scanf("%s%s%d", merk, warna, &ukuran);
    addAfter(L.first, merk, warna, ukuran, &L);

    // menghapus elemen pertama
    delFirst(&L);

    // mencetak seluruh isi list
    printElement(L);

    // menambah elemen setelah elemen kedua
    scanf("%s%s%d", merk, warna, &ukuran);
    addAfter(L.data[L.first].next, merk, warna, ukuran, &L);

    // menghapus elemen kedua
    delAfter(L.first, &L);

    // mencetak seluruh isi list
    printElement(L);

    // menghapus seluruh isi list
    delAll(&L);

    // mencetak seluruh isi list
    printElement(L);
    
    return 0;
}
