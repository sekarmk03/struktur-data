#include "header.h"

void createEmpty(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q) {
    int hasil = 0;
    if(Q.first == NULL) {
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q) {
    int hasil = 0;
    if(Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;
        while(bantu != NULL) {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(char nama[], char ktp[], queue *Q) {
    elemen *baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.ktp, ktp);
    strcpy(baru->kontainer.nama, nama);
    baru->next = NULL;
    if((*Q).first == NULL) {
        (*Q).first = baru;
    } else {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void addPriority(char nama[], char ktp[], int priority, queue *Q) {
    elemen *baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.ktp, ktp);
    strcpy(baru->kontainer.nama, nama);
    baru->next = NULL;
    if((*Q).first == NULL) {
        (*Q).first = baru;
        (*Q).last = baru;
    } else {
        if(priority == 1) {
            baru->next = (*Q).first;
            (*Q).first = baru;
        } else if(priority > countElement(*Q)) {
            add(ktp, nama, Q);
        } else {
            elemen *bantu = (*Q).first;
            int i = 1;
            while(bantu != NULL) {
                if(i == priority - 1) {
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

void del(queue *Q1) {
    if((*Q1).first != NULL) {
        elemen *hapus = (*Q1).first;
        if(countElement(*Q1) == 1) {
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        } else {
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void printQueue(queue *Q, int n, int Queue) {
    if(Queue != 0) {
        printf("sisa antrian:\n");
    } else {
        printf("gelombang %d:\n", Queue);
    }
    if((*Q).first != NULL) {
        elemen *bantu = (*Q).first;
        int i = 0;
        while(bantu != NULL && i < n) {
            printf("%s %s\n", bantu->kontainer.nama, bantu->kontainer.ktp);
            bantu = bantu->next;
            del(Q);
            i++;
        }
    } else {
        printf("queue kosong\n");
    }
}