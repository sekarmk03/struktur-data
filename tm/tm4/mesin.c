#include "header.h"

/* Membuat List */
void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}

/* Menghitung Jumlah Elemen List */
int countElement(list L){
    int hasil = 0;
    if(L.first != NULL){
        // jika list tidak kosong
        elemen *bantu;
        bantu = L.first; // dicek mulai dari elemen pertama
        while(bantu != NULL){
            // sampai elemen terakhir
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

/* Menambah Elemen di Awal List */
void addFirst(char nama[], char matkul[], char nilai[], list *L){
    elemen *baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.matkul, matkul);
    strcpy(baru->kontainer.nilai, nilai);
    if((*L).first == NULL){
        // Jika elemen belum ada
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    } else {
        // Jika elemen sudah ada
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

/* Menambah Elemen Setelah Elemen Tertentu */
void addAfter(elemen *before, char nama[], char matkul[], char nilai[], list *L){
    if(before != NULL){
        elemen *baru;
        baru = (elemen*)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.matkul, matkul);
        strcpy(baru->kontainer.nilai, nilai);
        if(before->next == NULL){
            // jika menambah elemen ke paling belakang
            baru->next = NULL;
            (*L).tail = baru;
        } else {
            // jika menambah elemen setelah elemen tertentu
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}
/* Menambah Elemen Sebelum Elemen Tertentu */
void addBefore(elemen *after, char nama[], char matkul[], char nilai[], list *L){
    if(after != NULL){
        elemen *baru;
        baru = (elemen*)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.matkul, matkul);
        strcpy(baru->kontainer.nilai, nilai);
        if(after->prev == NULL){
            // jika elemen ditambah sebelum elemen pertama
            baru->prev = NULL;
            (*L).first = baru;
        } else {
            // jika elemen ditambah di tengah2
            baru->prev = after->prev;
            after->prev->next = baru;
        }
        baru->next = after;
        after->prev = baru;
        baru = NULL;
    }
}

/* Menghapus Elemen Terakhir */
void addLast(char nama[], char matkul[], char nilai[], list *L){
    if((*L).first == NULL){
        addFirst(nama, matkul, nilai, L);
    } else {
        addAfter((*L).tail, nama, matkul, nilai, L);
    }
}

/* Menghapus Elemen Pertama */
void delFirst(list *L){
    if((*L).first != NULL){
        elemen *hapus = (*L).first;
        if(countElement(*L) == 1){
            // Jika elemen hanya 1
            (*L).first = NULL;
            (*L).tail == NULL;
        } else {
            // Jika elemen lebih dari 1
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

/* Menghapus Elemen Setelah Elemen Tertentu */
void delAfter(elemen *before, list *L){
    if(before != NULL){
        elemen *hapus = before->next;
        if(hapus != NULL){
            if(hapus->next == NULL){
                // Jika elemen terakhir yg dihapus
                before->next = NULL;
                (*L).tail = before;
            } else {
                // Jika elemen di tengah yg dihapus
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
            hapus->prev = NULL;
            free(hapus);
        }
    }
}

/* Menghapus Elemen Terakhir */
void delLast(list *L){
    if((*L).first != NULL){
        if(countElement(*L) == 1){
            // jika elemen hanya 1
            delFirst(L);
        } else {
            // jika elemen lebih dari 1
            delAfter((*L).tail->prev, L);
        }
    }
}

/* Menghapus Seluruh Elemen */
void delAll(list *L){
    if(countElement(*L) != 0){
        int i = 0;
        for(i = countElement(*L); i >= 1; i--){
            delLast(L);
        }
    }
}

/* Mencetak Seluruh Elemen */
void printElement(list L){
    if(L.first != NULL){
        elemen *bantu = L.first;
        // Menunjuk elemen satu per satu dari depan
        while(bantu != NULL){
            printf("%s %s %s\n", bantu->kontainer.nama, bantu->kontainer.matkul, bantu->kontainer.nilai);
            bantu = bantu->next;
        }
    } else {
        printf("List Kosong\n");
    }
    printf("========\n");
}

/* Mencetak Seluruh Elemen Terbalik */
void printReverse(list L){
    if(L.first != NULL){
        elemen *bantu = L.tail;
        // Menunjuk elemen satu per satu dari belakang
        while(bantu != NULL){
            printf("%s %s %s\n", bantu->kontainer.nama, bantu->kontainer.matkul, bantu->kontainer.nilai);
            bantu = bantu->prev;
        }
    } else {
        printf("List Kosong\n");
    }
    printf("========\n");
}