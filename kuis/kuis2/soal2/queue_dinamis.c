#include "header.h"

int main() {
    queue Q; // membuat variabel queue
    createEmpty(&Q); // membuat alokasi queue di memori
    char nama[100], alamat[100], dana[100]; // masukan
    int n = 0, m = 0, priority = 0;
    scanf("%d", &n); // jumlah elemen queue
    for (int i = 0; i < n; i++) {
        // masukan
        scanf("%s%d%s%s", nama, &priority, alamat, dana);
        // menambahkan masukan elemen ke queue
        addPriority(nama, alamat, dana, priority, &Q);
    }
    scanf("%d", &m); // jumlah yang menerima bantuan (yang harus di cetak)
    printQueue(&Q, m, 1); // mencetak penerima bantuan sebanyak m
    printQueue(&Q, countElement(Q) + 1, 0); // mencetak sisa antrian
    return 0;
}