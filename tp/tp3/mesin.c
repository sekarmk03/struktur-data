#include "header.h"

/* Membuat Stack Kosong */
void createEmpty(stack *S) {
    (*S).top = NULL;
}

/* Mengecek Stack Kosong */
int isEmpty(stack S) {
    int hasil = 0;
    if(S.top == NULL) {
        // jika elemen teratas null, maka hasil = 1
        hasil = 1;
    }
    // jika hasil bernilai 0, maka stack tidak kosong
    // jika hasil bernilai 1, maka stack kosong
    return hasil;
}

/* Menghitung Elemen Stack */
int countElement(stack S) {
    int hasil = 0;
    if(!isEmpty(S)) {
        // jika stack tidak kosong
        elemen* bantu;
        bantu = S.top;
        while(bantu != NULL) {
            // hitung elemen stack sampai bertemu elemen null
            hasil++;
            bantu = bantu->next;
        }
    }
    // kembalikan hasil perhitungan
    return hasil;
}

/* Memasukkan Data ke Elemen Stack */
void push(char tahun[], char judul[], char band[], stack *S) {
    elemen* baru;
    baru = (elemen*)malloc(sizeof(elemen)); // meminta memori sebesar elemen
    // memasukkan data
    strcpy(baru->kontainer.tahun, tahun);
    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.band, band);

    if((*S).top == NULL) {
        // jika stack masih kosong
        baru->next = NULL; // elemen kedua null
    } else {
        // jika stack sudah ada isinya
        baru->next = (*S).top; // elemen kedua = stack teratas sebelumnya
    }
    (*S).top = baru; // memperbarui elemen stack teratas
    baru = NULL;
}

/* Menghapus Elemen Stack */
void pop(stack *S) {
    if(!isEmpty(*S)) {
        // jika stack tidak kosong
        elemen *hapus = (*S).top;
        if(countElement(*S) == 1) {
            // jika elemen stack hanya 1
            (*S).top = NULL; // null kan elemen tersebut
        } else {
            // jika elemen lebih dari 1
            (*S).top = (*S).top->next; // pindahkan top ke elemen stack kedua
        }
        hapus->next = NULL;
        free(hapus);
    } else {
        printf("- Stack Kosong\n");
    }
}

/* Mencetak Seluruh Isi Elemen Stack */
void printStack(stack S, int stackNo) {
    // jika stack rock (stack 1)
    if(stackNo == 1) printf("Playlist Musik Rock:\n");
    // jika stack pop (stack 2)
    else if(stackNo == 2) printf("Playlist Musik Pop:\n");
    printf("===================\n");
    if(S.top != NULL) {
        // jika stack tidak kosong
        elemen* bantu = S.top;
        int i = 1;
        while(bantu != NULL) {
            // diulang sampai bantu bernilai null atau stack kosong
            // mencetak isi stack satu per satu (hanya judul lagu)
            printf("%d. %s\n", i, bantu->kontainer.judul);
            bantu = bantu->next;
            i++;
        }
    } else {
        // jika stack kosong
        // jika stack rock (stack 1)
        if(stackNo == 1) printf("BUKAN ANAK ROCK!\n");
        // jika stack pop (stack 2)
        else if(stackNo == 2) printf("BUKAN ANAK POP!\n");
    }
}

/* Menghitung Nilai ASCII Setiap Huruf dalam String */
int countAscii(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        // mengimpan jumlah ASCII per huruf
        count += str[i];
    }
    // mengembalikan jumlah total
    return count;
}

/* Memindahkan Musik ke Stack/Playlist yang Sesuai */
void musicPlaylist(stack *S1, stack *S2, stack *S3) {
    if(!isEmpty(*S1)) {
        // jika stack tidak kosong
        elemen* pindah = (*S1).top;
        while(pindah != NULL) {
            // memindahkan elemen
            // jika total ascii genap, elemen pindah ke playlist Rock
            if(countAscii(pindah->kontainer.judul) % 2 == 0) push(pindah->kontainer.tahun, pindah->kontainer.judul, pindah->kontainer.band, S2);
            // jika total ascii ganjil elemen pindah ke playlist Pop
            else push(pindah->kontainer.tahun, pindah->kontainer.judul, pindah->kontainer.band, S3);
            pindah = pindah->next;
        }
    } else {
        printf("- Stack Kosong\n");
    }
}