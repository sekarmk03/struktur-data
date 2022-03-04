#include "header.h"

/* Prosedur Membuat Stack */
void createEmpty(stack *S) {
    (*S).top = -1; // inisialisasi stack kosong
}

/* Fungsi Mengecek Apakah Stack Kosong */
int isEmpty(stack S) {
    int hasil = 0;
    if(S.top == -1) {
        // jika index top nya -1 maka stack kosong
        hasil = 1;
    }
    return hasil;
}

/* Fungsi Mengecek Apakah Stack Penuh */
int isFull(stack S) {
    int hasil = 0;
    if(S.top == 99) {
        // jika index top nya 99 maka stack sudah penuh
        hasil = 1;
    }
    return hasil;
}

/* Prosedur Menambah Elemen Stack */
void push(char nama[], char bahan[], stack *S) {
    if(isFull(*S) == 1) {
        // jika stack penuh
        printf("Stack penuh\n");
    } else {
        // jika stack belum penuh
        if(isEmpty(*S) == 1) {
            // jika stack masih kosong
            (*S).top = 0; // inisialisasi index
            // memasukkan data
            strcpy((*S).data[0].nama, nama);
            strcpy((*S).data[0].bahan, bahan);
        } else {
            // jika stack sudah ada isinya
            (*S).top = (*S).top + 1; // incremen index
            // memasukkan data
            strcpy((*S).data[(*S).top].nama, nama);
            strcpy((*S).data[(*S).top].bahan, bahan);
        }
    }
}

/* Prosedur Menghapus Elemen Stack */
void pop(stack *S) {
    if((*S).top == 0) {
        // jika elemen hanya 1
        (*S).top = -1;
    } else {
        // jika elemen lebih dari 1
        if((*S).top != -1) {
            // jika elemen ada
            // decrement
            (*S).top = (*S).top - 1;
        }
    }
}

/* Fungsi Memindahkan Elemen Stack */
void popPush(stack *S1, stack *S2) {
    if((*S1).top == 0) {
        // jika elemen hanya 1
        if(strcmp((*S1).data[0].nama, "0") != 0) {
            // pindahkan elemen yang bukan 0 ke stack lain
            // elemen 0 adalah kode untuk baju yang diambil
            push((*S1).data[0].nama, (*S1).data[0].bahan, S2);
        }
        (*S1).top = -1;
    } else {
        // jika elemen lebih dari 1
        if((*S1).top != -1) {
            // jika elemen ada
            if(strcmp((*S1).data[(*S1).top].nama, "0") != 0) {
                // pindahkan elemen yang bukan 0 ke stack lain
                // elemen 0 adalah kode untuk baju yang diambil
                push((*S1).data[(*S1).top].nama, (*S1).data[(*S1).top].bahan, S2);
            }
            // decrement
            (*S1).top = (*S1).top - 1;
        }
    }
}

/* Prosedur Mencetak Elemen Stack */
void printStack(stack S, int flag) {
    if(S.top != -1) {
        // jika stack tidak kosong
        int i;
        for(i = S.top; i >= 0; i--) {
            // cetak elemen dari yang teratas
            printf("%s %s\n", S.data[i].nama, S.data[i].bahan);
        }
    } else {
        // jika stack kosong
        if(flag == 1) {
            // jika stack utama yang kosong
            printf("kosong\n");
        }
    }
}

/* Prosedur Mencari Bahan Dalam Stack Utama */
int cariBahan(stack *S1, char cari[][100], int n) {
    int minIdx = n; // inisialisasi penanda index terkecil
    for (int i = 0; i < n; i++) {
        // untuk setiap bahan yang dicari
        for(int j = (*S1).top; j >= 0; j--) {
            // untuk setiap stack
            if(strcmp((*S1).data[j].nama, cari[i]) == 0) {
                // jika ketemu nama pemilik bahan
                // ganti nama dengan 0 agar tidak dipindah
                strcpy((*S1).data[j].nama, "0");
                // update nilai index terkecil ditemukannya bahan
                minIdx = j < minIdx ? j : minIdx;
            }
        }
    }
    // kembalikan index terkecil (pembatas pop)
    return minIdx;
}

/* Prosedur Memindahkan Elemen-elemen Stack */
void pindahBahan(stack *S1, stack *S2, int idxMin) {
    if((*S1).top != -1) {
        // jika stack tidak kosong
        for(int i = (*S1).top; i >= idxMin; i--) {
            // hapus dan pindahkan semua elemen
            // sampai elemen pada index terkecil
            popPush(S1, S2);
        }
    }
}