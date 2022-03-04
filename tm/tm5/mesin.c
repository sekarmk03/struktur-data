#include "header.h"

void createList(list *L) {
    (*L).first;
}

int countElementB (list L) {
    int hasil = 0;
    if(L.first != NULL) {
        eBaris *bantu;
        bantu = L.first;
        while(bantu != NULL) {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

int countElementK(eBaris L) {
    int hasil = 0;
    if(L.col !=NULL) {
        eKolom* bantu;
        bantu = L.col;
        while (bantu != NULL) {
            hasil++;
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

void addFirstB(char nama[], char tahun[], list *L) {
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.tahun, tahun);
    baru->col = NULL;
    if((*L).first == NULL) {
        baru->next = NULL;
    } else{
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addFirstK(char pemain[], eBaris *L) {
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.pemain, pemain);
    if((*L).col == NULL) {
        baru->next_kol = NULL;
    } else {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void addAfterB(eBaris* prev, char nama[], char tahun[], list *L) {
    eBaris* baru;
    baru = (eBaris *) malloc (sizeof (eBaris));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.tahun, tahun);
    baru->col = NULL;
    if(prev->next == NULL) {
        baru->next = NULL;
    } else {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addAfterK(eKolom* prev, char pemain[]) {
    eKolom* baru;
    baru = (eKolom *) malloc (sizeof (eKolom));
    strcpy(baru->kontainer_kol.pemain, pemain);
    if(prev->next_kol == NULL) {
        baru->next_kol = NULL;
    } else {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

void addLastB(char nama[], char tahun[], list *L) {
    if((*L).first == NULL) {
        addFirstB(nama, tahun, L);
    } else {
        eBaris *last = (*L).first;
        while(last->next != NULL) {
            last = last->next;
        }
        addAfterB(last, nama, tahun, L);
    }
}

void addLastK(char pemain[], eBaris *L) {
    if((*L).col == NULL) {
        addFirstK(pemain, L);
    } else {
        eKolom *last = (*L).col;
        while(last->next_kol != NULL) {
            last = last->next_kol;
        }
        addAfterK(last, pemain);
    }
}

void delFirstK(eBaris *L) {
    if((*L).col != NULL) {
        eKolom* hapus = (*L).col;
        if(countElementK(*L) == 1) {
            (*L).col = NULL;
        } else {
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delAfterK(eKolom* prev) {
    eKolom* hapus = prev->next_kol;
    if(hapus != NULL) {
        if(hapus->next_kol == NULL) {
            prev->next_kol = NULL;
        } else {
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void delLastK(eBaris *L) {
    if((*L).col != NULL) {
        if(countElementK(*L) == 1) {
            delFirstK(L);
        } else {
            eKolom *last = (*L).col;
            eKolom *before_last;
            while(last->next_kol != NULL) {
                before_last = last;
                last = last->next_kol;
            }
            delAfterK(before_last);
        }
    }
}

void delAllK(eBaris *L) {
    if(countElementK(*L) != 0) {
        int i;
        for(i=countElementK(*L);i>=1;i--) {
            delLastK(L);
        }
    }
}

void delFirstB(list *L) {
    if((*L).first != NULL) {
        eBaris *hapus = (*L).first;
        if(hapus->col != NULL) {
            delAllK(hapus);
        }
        if(countElementB(*L) == 1) {
            (*L).first = NULL;
        } else {
            (*L).first = (*L).first->next;
        }
        hapus->next = NULL;
        free(hapus);
    } else {
        printf("list kosong");
    }
}

void delAfterB(eBaris* prev) {
    if(prev != NULL) {
        eBaris *hapus = prev->next;
        if(hapus != NULL) {
            if(hapus->col != NULL) {
                delAllK(hapus);
            }
            if(hapus->next == NULL) {
                prev->next = NULL;
            } else {
                prev->next = hapus->next;
            }
            hapus->next = NULL;
            free(hapus);
        }
    }
}

void delLastB(list *L) {
    if((*L).first != NULL) {
        if(countElementB(*L) == 1) {
            delFirstB(L);
        } else {
            eBaris *last = (*L).first;
            eBaris *before_last;
            while(last->next != NULL) {
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

void delAllB(list *L) {
    if(countElementB(*L) != 0) {
        int i;
        for(i=countElementB(*L);i>=1;i--) {
            delLastB(L);
        }
    }
}

void printElement(list L) {
    if(L.first != NULL) {
        eBaris* bantu = L.first;
        int i = 1;
        while(bantu != NULL) {
            printf("elemen ke : %d\n", i);
            printf("nama : %s\n", bantu->kontainer.nama);
            printf("tahun : %s\n", bantu->kontainer.tahun);
            eKolom* eCol = bantu->col;
            while(eCol != NULL) {
                printf("pemain kuliah : %s\n", eCol->kontainer_kol.pemain);
                eCol = eCol->next_kol;
            }
            printf("------------\n");
            bantu = bantu->next;
            i = i + 1;
        }
    } else {
        printf("list kosong\n");
    }
}

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

/* prosedur mengurutkan elemen list */

void sortList(list *L) {
    if(countElement(*L) > 1) {
        // urutkan jika jumlah elemen > 1
        eBaris *i = L->first, *j; // buat pointer i dan j untuk membantu pengecekan elemen
        for(i = L->first; i->next != NULL; i = i->next) {
            // diulang sampai i menunjuk elemen terakhir
            // dimulai dari elemen pertama
            for(j = i->next; j != NULL; j = j->next) {
                // diulang sampai j menunjuk elemen terakhir
                // dimulai dari elemen setelah i
                if(strcmp(i->kontainer.tahun, j->kontainer.tahun) > 0) {
                    // jika rating elemen i > rating elemen j
                    // tukar
                    swap(i, j);
                }
            }
        }
    }
}

/* prosedur menukar elemen */

void swap(eBaris *a, eBaris *b) {
    // tukar elemen yg ditunjuk oleh pointer a dan b
    mahasiswa temp = a->kontainer;
    a->kontainer = b->kontainer;
    b->kontainer = temp;
}
