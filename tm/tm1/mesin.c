#include "header.h"

/* Prosedur membuat list sesuai jumlah maks elemen
   Menginisialisasi pointer next dengan -2
   yang artinya elemen tersebut masih kosong */
void createList(list *L) {
    (*L).first = -1;
    int i = 0;
    for ( i = 0; i < n; i++) {
        (*L).data[i].next = -2;
    }
}

/* Fungsi menghitung elemen dalam list
   Selama pointer next bukan -1 (null)
   maka akan dihitung sbg elemen isi */
int countElement(list L) {
    int hasil = 0;
    if(L.first != -1){
        int hitung = 0;
        hitung = L.first;
        while (hitung != -1) {
            hasil++;
            hitung = L.data[hitung].next;
        }
    }
    // mengembalikan nilai var hasil
    return hasil;
}

/* Fungsi mencari elemen kosong
   Menyimpan indeks yang kosong
   (yang pointer next nya -2)
   lalu dikembalikan */
int emptyElement(list L) {
    int hasil = -1;
    if(countElement(L) < n) {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < n)) {
            if(L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            } else {
                i++;
            }
        }
    }
    return hasil;
}

/* Prosedur menambahkan elemen di awal list */
void addFirst(char merk[30], char warna[30], int ukuran, list *L) {
    // jika jumlah elemen belum maksimal
    if(countElement(*L) < n) {
        // mencari letak elemen kosong
        int baru = emptyElement(*L);
        // memasukkan data
        strcpy((*L).data[baru].inventory.merk, merk);
        strcpy((*L).data[baru].inventory.warna, warna);
        (*L).data[baru].inventory.ukuran = ukuran;
        if((*L).first == -1) {
            // jika elemen pertama
            (*L).data[baru].next = -1;
        } else {
            // jika bukan elemen pertama
            (*L).data[baru].next = (*L).first;
        }
        (*L).first = baru;
    } else {
        // jika elemen mencapai batas maksimal (sudah terisi semua)
        printf("List sudah tidak dapat ditambah\n");
    }
}

/* Prosedur menambahkan elemen setelah elemen tertentu */
void addAfter(int prev, char merk[30], char warna[30], int ukuran, list *L) {
    // jika jumlah elemen belum maksimal
    if(countElement(*L) < n) {
        // mencari letak elemen kosong
        int baru = emptyElement(*L);
        // memasukkan data
        strcpy((*L).data[baru].inventory.merk, merk);
        strcpy((*L).data[baru].inventory.warna, warna);
        (*L).data[baru].inventory.ukuran = ukuran;
        if((*L).data[prev].next == -1) {
            // jika ditambah setelah elemen pertama
            (*L).data[baru].next = -1;
        } else {
            // jika ditambah setelah elemen tertentu
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    } else {
        // jika elemen mencapai batas maksimal (sudah terisi semua)
        printf("List sudah tidak dapat ditambah\n");
    }
}

/* Prosedur menambah elemen di akhir list */
void addLast(char merk[30], char warna[30], int ukuran, list *L) {
    if((*L).first == -1) {
        // jika list masih kosong
        addFirst(merk, warna, ukuran, L);
    } else {
        // jika list sudah terisi
        if(countElement(*L) < 10) {
            int prev = (*L).first;
            // mencari elemen terakhir
            while((*L).data[prev].next != -1) {
                prev = (*L).data[prev].next;
            }
            addAfter(prev, merk, warna, ukuran, L);
        } else {
            // jika elemen mencapai batas maksimal (sudah terisi semua)
            printf("List sudah tidak dapat ditambah\n");
        }
    }
}

/* Prosedur menghapus elemen pertama */
void delFirst(list *L) {
    if((*L).first != -1) {
        // jika list ada isinya
        int hapus = (*L).first;
        if(countElement(*L) == 1) {
            // jika elemen hanya 1
            (*L).first = -1;
        } else {
            // jika elemen > 1
            (*L).first = (*L).data[hapus].next;
        }
        // mengosongkan elemen
        (*L).data[hapus].next = -2;
    } else {
        // jika list kosong
        printf("List kosong\n");
    }
}

/* Prosedur menghapus elemen setelah elemen tertentu */
void delAfter(int prev, list *L) {
    int hapus = (*L).data[prev].next;
    if(hapus != -1) {
        // jika prev bukan elemen terakhir
        if((*L).data[hapus].next == -1) {
            // jika menghapus elemen terakhir
            (*L).data[prev].next = -1;
        } else {
            // jika menghapus elemen setelah elemen tertentu
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        // mengosongkan elemen
        (*L).data[hapus].next = -2;
    }
}

/* Prosedur menghapus elemen terakhir */
void delLast(list *L) {
    if((*L).first != -1) {
        // jika list tidak kosong
        if(countElement(*L) == 1) {
            // jika elemen hanya 1
            delFirst(L);
        } else {
            // jika elemen > 1
            int hapus = (*L).first;
            int prev = 0;
            // mencari elemen terakhir
            while((*L).data[hapus].next != -1) {
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            delAfter(prev, L);
        }
    } else {
        // jika list kosong
        printf("List kosong\n");
    }
}

/* Prosedur menghapus seluruh isi list */
void delAll(list *L) {
    int i = 0;
    // hapus semua elemen dari belakang
    for (i = countElement(*L); i >= 1; i--) {
        delLast(L);
    }
}

/* Prosedur mencetak seluruh isi list */
void printElement(list L) {
    if(L.first != -1) {
        // jika list tidak kosong
        int tunjuk = L.first;
        int i = 0;
        while(tunjuk != -1) {
            // cetak sampai elemen terakhir
            printf("%s %s %d\n", L.data[tunjuk].inventory.merk, L.data[tunjuk].inventory.warna, L.data[tunjuk].inventory.ukuran);
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    } else {
        // jika list kosong
        printf("List kosong\n");
    }
    printf("========\n");
}
