#include "header.h"

/* Prosedur Membuat Queue */
void createEmpty(queue *Q) {
    (*Q).first = NULL; // kepala queue
    (*Q).last = NULL; // ekor queue
}

/* Fungsi Mengecek Apakah Queue Kosong */
int isEmpty(queue Q) {
    int hasil = 0;
    if(Q.first == NULL) {
        // jika kepalanya NULL maka queue kosong
        hasil = 1;
    }
    return hasil;
}

/* Fungsi Menghitung Element Queue */
int countElement(queue Q) {
    int hasil = 0;
    if(Q.first != NULL) {
        // jika kepala queue tidak NULL
        elemen *bantu;
        bantu = Q.first;
        while(bantu != NULL) {
            // telusuri / hitung elemen satu per satu
            hasil++; // tandai
            bantu = bantu->next;
        }
    }
    return hasil;
}

/* Prosedur Menambah Elemen Queue Berprioritas */
void addPriority(dtPengantri pengantri, queue *Q) {
    elemen *baru; // pointer bertipe elemen
    baru = (elemen*)malloc(sizeof(elemen)); // memesan memori
    // memasukkan data elemen
    baru->kontainer = pengantri;
    baru->next = NULL;
    if((*Q).first == NULL) {
        // jika queue masih kosong
        (*Q).first = baru;
        (*Q).last = baru;
    } else {
        // jika queue sudah ada isinya
        elemen *bantu1 = (*Q).first;
        elemen *bantu2 = (*Q).last;
        if(baru->kontainer.priority < bantu1->kontainer.priority) {
            // jika prioritasnya lebih kecil dari elemen queue pertama
            baru->next = (*Q).first;
            (*Q).first = baru;
        } else if(baru->kontainer.priority >= bantu2->kontainer.priority) {
            // jika prioritasnya lebih besar dari elemen queue terakhir
            baru->next = NULL;
            bantu2->next = baru;
            (*Q).last = baru;
        } else {
            // jika di tengah2
            int stop = 0;
            while(bantu1 != NULL && stop == 0) {
                // diulang selama elemen belum habis dan
                // belum menemukan tempat untuk elemen baru
                if(baru->kontainer.priority >= bantu1->next->kontainer.priority) {
                    // jika prioritas elemen baru lebih besar atau sama dengan
                    // jalankan terus ke depan
                    bantu1 = bantu1->next;
                } else {
                    // jika prioritas elemen baru lebih kecil
                    // berhenti
                    baru->next = bantu1->next; // hubungkan elemen baru ke next elemen bantu
                    bantu1->next = baru; // hubungkan next elemen baru ke elemen baru
                    stop = 1; // tandai agar loop berhenti
                }
            }
        }
    }
    baru = NULL;
}

/* Menghapus Elemen Queue */
void del(queue *Q1) {
    if((*Q1).first != NULL) {
        // jika queue tidak kosong
        elemen *hapus = (*Q1).first;
        if(countElement(*Q1) == 1) {
            // jika elemen hanya 1
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        } else {
            // jika elemen banyak
            // ubah kepala queue ke elemen kedua
            (*Q1).first = (*Q1).first->next;
            // putuskan hubungan elemen pertama
            hapus->next = NULL;
        }
        // hapus elemen pertama
        free(hapus);
    }
}

/*
void pindahQueue(queue *Q1) {
    if((*Q1).first != NULL) {
        int count = 0;
        int temp = (*Q1).first->kontainer.waktu;
        while(temp < 360) {
            printf("> %s", (*Q1).first->kontainer.nama);
            del(Q1);
            temp += (*Q1).first->kontainer.waktu;
        }
        printf("done\n");
    } else {
        printf("Antrian kosong.\n");
    }
}

void printQueue(queue Q) {
    printf("masuk\n");
    if(Q.first != NULL) {
        elemen *bantu = Q.first;
        while(bantu != NULL) {
            printf("%s\n", bantu->kontainer.nama);
            bantu = bantu->next;
        }
    } else {
        printf("Antrian kosong.\n");
    }
}
*/

/* Mencetak Isi Elemen Queue */
void printQueue(queue Q) {
    if(Q.first != NULL) {
        elemen *bantu = Q.first; // elemen pointer untuk membantu penelusuran queue
        int count = 0;
        while(bantu != NULL) {
            // selama belum mencapai elemen terakhir
            count += bantu->kontainer.waktu;
            if(count <= 360) {
                // jika waktu kurang dari atau sama dengan 6 jam
                // antrian lanjut terus
                bantu = bantu->next;
            }
            if(bantu == NULL) {
                // jika antrian habis
                printf("Antrian kosong.\n");
            } else if(bantu != NULL && count > 360){
                // jika antrian masih ada sisa tetapi sudah lebih dari 6 jam
                printf("%s\n", bantu->kontainer.nama);
                bantu = bantu->next;
            }
        }
    } else {
        // jika dari awal queue sudah kosong
        printf("Antrian kosong.\n");
    }
}
