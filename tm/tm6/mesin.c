#include "header.h"

/* Membuat List */
void createList(list *L) {
    (*L).first;
}

/* Menghitung Jumlah Baris */
int countElementB (list L) {
    int hasil = 0;
    if(L.first != NULL) {
        eBaris *bantu;
        bantu = L.first;
        // dicek satu per satu
        while(bantu != NULL) {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

/* Menghitung Jumlah Kolom */
int countElementK(eBaris L) {
    int hasil = 0;
    if(L.col !=NULL) {
        eKolom* bantu;
        bantu = L.col;
        // dicek satu per satu
        while (bantu != NULL) {
            hasil++;
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

/* Menambah Baris ke Awal List */
void addFirstB(char nama[], char tahun[], list *L) {
    eBaris* baru;
    baru = (eBaris*)malloc(sizeof(eBaris));
    // memasukan data baru
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.tahun, tahun);
    // membuat tempat untuk kolom
    baru->col = NULL;
    if((*L).first == NULL) {
        baru->next = NULL;
    } else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

/* Menambah Kolom di Awal List of List */
void addFirstK(char pemain[], eBaris *L) {
    eKolom* baru;
    baru = (eKolom*)malloc(sizeof(eKolom));
    // memasukan data baru
    strcpy(baru->kontainer_kol.pemain, pemain);
    if((*L).col == NULL) {
        baru->next_kol = NULL;
    } else {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

/* Menambah Elemen Baris Setelah Elemen Tertentu */
void addAfterB(eBaris* prev, char nama[], char tahun[], list *L) {
    eBaris* baru;
    baru = (eBaris*)malloc(sizeof(eBaris));
    // memasukan data
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.tahun, tahun);
    // membuat tempat untuk kolom
    baru->col = NULL;
    if(prev->next == NULL) {
        baru->next = NULL;
    } else {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

/* Menambah Elemen Kolom Setelah Elemen Tertentu */
void addAfterK(eKolom* prev, char pemain[]) {
    eKolom* baru;
    baru = (eKolom*)malloc(sizeof(eKolom));
    // memasukan data
    strcpy(baru->kontainer_kol.pemain, pemain);
    if(prev->next_kol == NULL) {
        baru->next_kol = NULL;
    } else {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

/* Menambah Baris di Akhir List */
void addLastB(char nama[], char tahun[], list *L) {
    if((*L).first == NULL) {
        // jika list masih kosong
        addFirstB(nama, tahun, L);
    } else {
        // jika list sudah ada isinya
        // cari baris terakhir
        eBaris *last = (*L).first;
        while(last->next != NULL) {
            last = last->next;
        }
        addAfterB(last, nama, tahun, L);
    }
}

/* Menambah Elemen Kolom di Akhir Kolom Suatu Baris */
void addLastK(char pemain[], eBaris *L) {
    if((*L).col == NULL) {
        // jika kolom kosong
        addFirstK(pemain, L);
    } else {
        // jika kolom sudah ada isinya
        // cari kolom terakhir
        eKolom *last = (*L).col;
        while(last->next_kol != NULL) {
            last = last->next_kol;
        }
        addAfterK(last, pemain);
    }
}

/* Menghapus Elemen Kolom Pertama Suatu Baris */
void delFirstK(eBaris *L) {
    if((*L).col != NULL) {
        eKolom* hapus = (*L).col;
        if(countElementK(*L) == 1) {
            // jika elemen kolom hanya 1
            (*L).col = NULL;
        } else {
            // jika elemen kolom banyak
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

/* Manghapus Elemen Kolom Setelah Elemen Kolom Tertentu */
void delAfterK(eKolom* prev) {
    eKolom* hapus = prev->next_kol;
    if(hapus != NULL) {
        // jika elemen yg mau dihapus 'ada'
        if(hapus->next_kol == NULL) {
            // jika elemen terakhir
            prev->next_kol = NULL;
        } else {
            // jika bukan elemen terakhir
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

/* Menghapus Elemen Terakhir Kolom Suatu Baris */
void delLastK(eBaris *L) {
    if((*L).col != NULL) {
        // jika kolom tidak kosong
        if(countElementK(*L) == 1) {
            // jika elemennya hanya 1
            delFirstK(L);
        } else {
            // jika elemen banyak
            eKolom *last = (*L).col;
            eKolom *before_last;
            // cari elemen terakhir
            while(last->next_kol != NULL) {
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

/* Menghapus Seluruh Elemen Kolom Suatu Baris */
void delAllK(eBaris *L) {
    if(countElementK(*L) != 0) {
        int i;
        for(i = countElementK(*L); i >= 1; i--) {
            // Elemen dihapus satu per satu dari belakang
            delLastK(L);
        }
    }
}

/* Menghapus Baris Pertama List */
void delFirstB(list *L) {
    if((*L).first != NULL) {
        eBaris *hapus = (*L).first;
        if(hapus->col != NULL) {
            // Hapus seluruh elemen kolom jika ada
            delAllK(hapus);
        }
        if(countElementB(*L) == 1) {
            // jika baris list hanya 1
            (*L).first = NULL;
        } else {
            // jika baris list banyak
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    } else {
        // jika list kosong
        printf("list kosong");
    }
}

/* Menghapus Baris Setelah Baris Tertentu */
void delAfterB(eBaris* prev) {
    if(prev != NULL) {
        eBaris *hapus = prev->next;
        if(hapus != NULL) {
            // jika baris yg ingin dihapus 'ada'
            if(hapus->col != NULL) {
                // hapus seluruh elemen kolom baris tsb jika ada
                delAllK(hapus);
            }
            if(hapus->next == NULL) {
                // jika baris hanya 1
                prev->next = NULL;
            } else {
                // jika barus banyak
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

/* Menghapus Baris Terakhir List */
void delLastB(list *L) {
    if((*L).first != NULL) {
        // jika list tidak kosong
        if(countElementB(*L) == 1) {
            // jika list hanya 1
            delFirstB(L);
        } else {
            // jika list banyak
            eBaris *last = (*L).first;
            eBaris *before_last;
            // cari baris terakhir
            while(last->next != NULL) {
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

/* Menghapus Seluruh Baris */
void delAllB(list *L) {
    if(countElementB(*L) != 0) {
        int i;
        for(i=countElementB(*L);i>=1;i--) {
            // dihapus satu per satu dari belakang
            delLastB(L);
        }
    }
}

/* Mencetak Seluruh Elemen Kolom dan Baris */
void printElement(list L) {
    if(L.first != NULL) {
        eBaris* bantu = L.first;
        int i = 1;
        while(bantu != NULL) {
            // mencetak baris
            printf("%s %s\n", bantu->kontainer.nama, bantu->kontainer.tahun);
            eKolom* eCol = bantu->col;
            while(eCol != NULL) {
                // mencetak kolom
                printf("- %s\n", eCol->kontainer_kol.pemain);
                eCol = eCol->next_kol;
            }
            printf("==================\n");
            bantu = bantu->next;
            i = i + 1;
        }
    } else {
        // jika list kosong
        printf("list kosong\n");
    }
}


/* prosedur mengurutkan elemen list */
void sortList(list *L) {
    if(countElementB(*L) > 1) {
        // urutkan jika jumlah elemen > 1
        eBaris *i = L->first, *j; // buat pointer i dan j untuk membantu pengecekan elemen
        for(i = L->first; i->next != NULL; i = i->next) {
            // diulang sampai i menunjuk elemen terakhir
            // dimulai dari elemen pertama
            for(j = i->next; j != NULL; j = j->next) {
                // diulang sampai j menunjuk elemen terakhir
                // dimulai dari elemen setelah i
                if(strcmp(i->kontainer.tahun, j->kontainer.tahun) > 0) {
                    // jika tahun elemen i > tahun elemen j
                    // tukar
                    swap(i, j);
                }
            }
        }
    }
}

/* prosedur menukar elemen */
void swap(eBaris *a, eBaris *b) {
    // tukar elemen baris yg ditunjuk oleh pointer a dan b
    mahasiswa temp = a->kontainer;
    a->kontainer = b->kontainer;
    b->kontainer = temp;
    eKolom* eCol1 = a->col;
    eKolom* eCol2 = b->col;
    // menukar elemen kolom pada baris yang ditunjuk pointer a dan b
    while(eCol1 != NULL) {
        matkul tmp = eCol1->kontainer_kol;
        eCol1->kontainer_kol = eCol2->kontainer_kol;
        eCol2->kontainer_kol = tmp;
        eCol1 = eCol1->next_kol;
        eCol2 = eCol2->next_kol;
    }
}

/* Mengurutkan Masukan di Awal */
/* Prosedur ini masih dalam tahap perbaikan */
eBaris *sortDinamyc(list *L2, char nama[], char tahun[]) {
    eBaris* prev, *val;
    int posisi = 1;
    int cek = 0;
    eBaris* tunjuk2 = (*L2).first;
    prev = (*L2).first;
    while(tunjuk2 != NULL && cek == 0) {
        printf("masuk");
        if(strcmp(tahun, tunjuk2 -> kontainer.tahun) < 0 && posisi == 1) {
            printf("masuk1");
            // addFirstB(nama, tahun, L2);
            // cek = 1;
            // val = L2->first;
        }else if(strcmp(tahun, tunjuk2 -> kontainer.tahun) < 0) {
            printf("masuk2");
            // addAfterB(prev, nama, tahun, L2);
            // cek = 1;
            // val = prev->next;
        }else if(strcmp(tahun, tunjuk2 -> kontainer.tahun) > 0) {
            printf("masuk3");
            // addLastB(nama, tahun, L2);
            // cek = 1;
            // val = tunjuk2;
        }
        if(posisi > 1) {
            prev = prev -> next;
        }
        printf("posisi %d\njml %d\n", posisi, countElementB(*L2));
        posisi++;
        tunjuk2 = tunjuk2 -> next;
        printf("masak");
    }
    return val;
}
