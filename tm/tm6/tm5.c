#include "header.h"

int main() {
    list L2; // deklarasi list
    createList(&L2); // membuat list
    int n = 0; // jumlah masukan baris
    char nama[50], tahun[50], pemain[50]; // masukan
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // masukan baris
        scanf("%s%s", nama, tahun);
        addFirstB(nama, tahun, &L2);
        // masukan kolom
        scanf("%s", pemain);
        addLastK(pemain, L2.first);
        scanf("%s", pemain);
        addFirstK(pemain, L2.first);
        scanf("%s", pemain);
        addAfterK(L2.first->col, pemain);
        scanf("%s", pemain);
        addLastK(pemain, L2.first);
    }
    sortList(&L2); // mengurutkan elemen list
    delAfterK(L2.first->next->col->next_kol); // menghapus elemen baris kedua kolom kedua
    delLastB(&L2); // menghapus baris terakhir
    delFirstK(L2.first); // menghapus elemen pertama kolom pertama
    printElement(L2); // mencetak list
    return 0;
}