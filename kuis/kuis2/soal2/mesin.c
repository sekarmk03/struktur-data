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

/*  */
void add(char nama[], char alamat[], char dana[], int priority, queue *Q) {
    elemen *baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.alamat, alamat);
    strcpy(baru->kontainer.dana, dana);
    baru->kontainer.priority = priority;
    baru->next = NULL;
    if((*Q).first == NULL) {
        (*Q).first = baru;
    } else {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

/* Prosedur Menambah Elemen Queue Berprioritas */
void addPriority(char nama[], char alamat[], char dana[], int priority, queue *Q) {
    elemen *baru; // pointer bertipe elemen
    baru = (elemen*)malloc(sizeof(elemen)); // memesan memori
    // memasukkan data
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.alamat, alamat);
    strcpy(baru->kontainer.dana, dana);
    baru->kontainer.priority = priority;
    baru->next = NULL;

    if((*Q).first == NULL) {
        // jika queue sebelumnya masih kosong
        // elemen baru menjadi elemen pertama dan terakhir
        (*Q).first = baru;
        (*Q).last = baru;
    } else {
        // Jika priority queue berurutan sesuai besar priority
        // (*Q).first = baru;
        /*elemen *bantu1 = (*Q).first;
        elemen *bantu2 = (*Q).last;
        if(baru->kontainer.priority <= bantu1->kontainer.priority) {
            baru->next = (*Q).first;
            (*Q).first = baru;
        } else if(baru->kontainer.priority > bantu2->kontainer.priority) {
            baru->next = NULL;
            bantu2->next = baru;
            (*Q).last = baru;
        } else {
            int stop = 0;
            while(bantu1 != NULL && stop == 0) {
                if(bantu1->next->kontainer.priority < baru->kontainer.priority) {
                    // baru->next = bantu1->next;
                    // bantu1->next = baru;
                    // bantu1 = baru->next;
                    bantu1 = bantu1->next;
                } else {
                    baru->next = bantu1->next;
                    bantu1->next = baru;
                    stop = 1;
                }
            }
        }*/
        // jika priority queue relative
        if(priority == 1) {
            // jika priority nya 1 maka menjadi elemen pertama
            baru->next = (*Q).first;
            (*Q).first = baru;
        } else if(priority > countElement(*Q)) {
            // jika priority nya lebih besar dari jumlah elemen
            // maka menjadi elemen terakhir
            baru->next = NULL;
            (*Q).last->next = baru;
            (*Q).last = baru;
        } else {
            // jika priority di tengah2
            // letakkan elemen sesuai priority
            elemen *bantu = (*Q).first;
            int i = 1;
            while(bantu != NULL) {
                // jika i sekarang adalah elemen sebelum priority
                if(i == priority - 1) {
                    // menghubungkan elemen ke elemen baru
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                bantu = bantu->next;
                i++;
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

/* Mencetak Elemen Queue */
void printQueue(queue *Q, int n, int Queue) {
    if(Queue != 0) {
        // queue dengan kode bukan nol untuk mencetak bantuan tersalurkan
        printf("Bantuan Tersalurkan:\n");
    } else {
        // queue dengan kode nol untuk mencetak sisa antrian
        printf("\nAntrian berisi:\n");
    }
    if((*Q).first != NULL) {
        // jika queue tidak kosong
        elemen *bantu = (*Q).first;
        int i = 0;
        while(bantu != NULL && i < n) {
            // print queue sebanyak n atau sampai mencapai elemen terakhir
            printf("%s %d %s %s\n", bantu->kontainer.nama, bantu->kontainer.priority, bantu->kontainer.alamat, bantu->kontainer.dana);
            bantu = bantu->next;
            // queue yang sudah dicetak dihapus
            del(Q);
            i++;
        }
    } else {
        printf("queue kosong\n");
    }
}