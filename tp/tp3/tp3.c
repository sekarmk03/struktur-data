#include "header.h"

int main() {
    stack SAll, SRock, SPop; // deklarasi nama stack
    // membuat stack kosong
    createEmpty(&SAll);
    createEmpty(&SRock);
    createEmpty(&SPop);
    // membuat variable bantuan masukan
    char tahun[50], judul[50], band[50];
    // jumlah elemen dalam stack
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // meminta masukan data elemen stack
        scanf("%s%s%s", tahun, judul, band);
        // memasukkan data ke stack general
        push(tahun, judul, band, &SAll);
    }
    // memindahkan isi stack
    musicPlaylist(&SAll, &SRock, &SPop);
    // mencetak stack
    printStack(SRock, 1); // stack rock
    printf("\n");
    printStack(SPop, 2); // stack pop
    return 0;
}