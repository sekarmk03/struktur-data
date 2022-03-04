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
void addFirst(char nama[], int harga, int kode, list *L){
    elemen *baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;
    baru->kontainer.kode = kode;
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
void addAfter(elemen *before, char nama[], int harga, int kode, list *L){
    if(before != NULL){
        elemen *baru;
        baru = (elemen*)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nama, nama);
        baru->kontainer.harga = harga;
        baru->kontainer.kode = kode;
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

/* Menghapus Elemen Terakhir */
void addLast(char nama[], int harga, int kode, list *L){
    if((*L).first == NULL){
        addFirst(nama, harga, kode, L);
    } else {
        addAfter((*L).tail, nama, harga, kode, L);
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
            printf("%s %d %d\n", bantu->kontainer.nama, bantu->kontainer.harga, bantu->kontainer.kode);
            bantu = bantu->next;
        }
    } else {
        printf("=================\n Loh kok gaada:(\n=================\n");
    }
}

/* prosedur mengurutkan elemen list */
void sortList(list *L, char type[], char by) {
    if(countElement(*L) > 1) {
        // urutkan jika jumlah elemen > 1
        elemen *i = L->first, *j; // buat pointer i dan j untuk membantu pengecekan elemen
        for(i = L->first; i->next != NULL; i = i->next) {
            // diulang sampai i menunjuk elemen terakhir
            // dimulai dari elemen pertama
            for(j = i->next; j != NULL; j = j->next) {
                // diulang sampai j menunjuk elemen terakhir
                // dimulai dari elemen setelah i
                if(strcmp(type, "Asc") == 0) {
                    // jika pengurutan ascending
                    if(by == 'H') {
                        if(i->kontainer.harga > j->kontainer.harga) {
                            // jika harga elemen i > harga elemen j
                            // tukar
                            swap(i, j);
                        }
                    } else {
                        if(i->kontainer.kode > j->kontainer.kode) {
                            // jika kode elemen i > kode elemen j
                            // tukar
                            swap(i, j);
                        }
                    }
                } else {
                    // jika pengurutan descending
                    if(by == 'H') {
                        if(i->kontainer.harga < j->kontainer.harga) {
                            // jika harga elemen i < harga elemen j
                            // tukar
                            swap(i, j);
                        }
                    } else {
                        if(i->kontainer.kode < j->kontainer.kode) {
                            // jika kode elemen i < kode elemen j
                            // tukar
                            swap(i, j);
                        }
                    }
                }
            }
        }
    }
}

/* prosedur menukar elemen */
void swap(elemen *a, elemen *b) {
    // tukar elemen yg ditunjuk oleh pointer a dan b
    dataBarang temp = a->kontainer;
    a->kontainer = b->kontainer;
    b->kontainer = temp;
}