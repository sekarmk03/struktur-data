#include "header.h"

int main() {
    stack S1[30], S2[30]; // deklarasi array of stack
    char nama[100], bahan[100]; // masukan
    int n = 0, m = 0;
    scanf("%d", &n); // jumlah stack
    for (int i = 0; i < n; i++) {
        // membuat stack
        createEmpty(&S1[i]);
        createEmpty(&S2[i]);
        // masukan dari penanda 1 sampai 0
        int start = 1;
        scanf("%d", &start);
        if(start == 1) {
            do {
                scanf("%s", nama);
                if(strcmp(nama, "0") != 0) {
                    scanf("%s", bahan);
                    // tambahkan masukan sebagai elemen stack
                    push(nama, bahan, &S1[i]);
                }
                // masukan berhenti saat memasukkan 0
            } while (strcmp(nama, "0") != 0);
        }
    }
    scanf("%d", &m); // jumlah orang yang mengambil baju
    char ambil[m][100];
    for (int i = 0; i < m; i++) {
        scanf("%s", ambil[i]); // nama yang dicari
    }
    for (int i = 0; i < n; i++) {
        // mencari bahan
        // menghasilkan nilai index terakhir pembatas pop
        int idx = cariBahan(&S1[i], ambil, m);
        if(idx != m) {
            // jika bahan yang dicari ditemukan
            // pindahkan bahan sampai mencapai index pembatas
            pindahBahan(&S1[i], &S2[i], idx);
        }
    }
    // mencetak bahan yang tersisa
    for (int i = 0; i < n; i++) {
        printf("stack %d:\n", i+1);
        printStack(S1[i], 1);
        printf("\n");
    }
    // mencetak bahan yang dipindah ke tumpukan lain
    for (int i = n - 1; i >= 0; i--) {
        printf("batas stack %d\n", i+1);
        printStack(S2[i], 0);
    }
    return 0;
}