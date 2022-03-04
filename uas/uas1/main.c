#include "header.h"

int main() {
    // deklarasi tree
    tree T;
    data dt;
    Idx = 0;
    scanf("%d %d", &dt.kiri, &dt.kanan);
    // membuat tree/root utama
    makeTree(dt, &T);
    // memasukkan data, data pada child di generate berdasarkan parents
    addData(dt.kiri, dt.kanan, T.root);

    // keluaran
    if (Idx == 0) {
        // jika hanya ada parent root utama
        printf("%d %d\n", dt.kiri, dt.kanan);
    } else {
        // jika ada anaknya
        int i;
        for (i = 0; i < Idx; i++) {
            // keluaran disimpan dalam array global
            printf("%d", tampungOutput[i]);
            if(i < Idx - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // addRight(tempRight.kiri, tempRight.kanan / 2, T.root);
    return 0;
}