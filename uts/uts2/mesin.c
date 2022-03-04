#include "header.h"

/* Membuat List */
void createList(list *L) {
    (*L).first;
}

/* Menghitung Jumlah Baris */
int countElementB (list L) {
    int hasil = 0;
    if(L.first != NULL) {
        eBaris *bantu; // pointer bertipe elemen baris
        bantu = L.first; // baris pertama
        // dicek satu per satu
        while(bantu != NULL) {
            // list ditelusuri oleh pointer bantu
            // sampai menemukan NULL yang merupakan akhir list
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
        eKolom* bantu; // pointer bertipe elemen kolom
        bantu = L.col; // elemen pertama
        // dicek satu per satu
        while (bantu != NULL) {
            // list ditelusuri oleh pointer bantu
            // sampai menemukan NULL yang merupakan akhir list
            hasil++;
            bantu = bantu->next_kol;
        }
    }
    return hasil;
}

/* Menambah Baris di Awal List */
void addFirstB(restoran Resto, list *L) {
    eBaris *baru; // pointer bertipe elemen baris
    baru = (eBaris *)malloc(sizeof(eBaris)); // meminta alokasi memori
    strcpy(baru->kontainer.nama, Resto.nama); // masukan data
    baru->col = NULL; // membuat kolom kosong
    if ((*L).first == NULL) {
        // jika dimasukan ke list kosong
        baru->next = NULL;
    } else {
        // jika dimasukan ke list berisi
        baru->next = (*L).first;
    }
    // pointer first baris menunjuk ke elemen yg ditunjuk pointer baru
    (*L).first = baru;
    // pointer baru dibebaskan
    baru = NULL;
}

/* Menambah Kolom di Awal List Baris */
void addFirstK(menuRestoran Menu, eBaris *L) {
    eKolom *baru; // pointer bertipe elemen kolom
    baru = (eKolom *)malloc(sizeof(eKolom)); // meminta alokasi memori
    strcpy(baru->kontainer_kol.menu, Menu.menu); // masukan data
    baru->kontainer_kol.harga = Menu.harga; // masukan data
    if ((*L).col == NULL) {
        // jika dimasukan ke list kosong
        baru->next_kol = NULL;
    } else {
        // jika dimasukan ke list berisi
        baru->next_kol = (*L).col;
    }
    // pointer first kolom menunjuk ke elemen yg ditunjuk pointer baru
    (*L).col = baru;
    // pointer baru dibebaskan
    baru = NULL;
}

/* Menambah Baris Setelah Baris Tertentu */
void addAfterB(eBaris *prev, restoran Resto, list *L) {
    eBaris *baru; // pointer bertipe elemen baris
    baru = (eBaris *)malloc(sizeof(eBaris)); // meminta alokasi memori
    strcpy(baru->kontainer.nama, Resto.nama); // masukan data
    baru->col = NULL; // membuat kolom kosong
    if (prev->next == NULL) {
        // jika dimasukan setelah elemen terakhir
        baru->next = NULL;
    } else {
        // jika dimasukan di tengah
        baru->next = prev->next;
    }
    // menghubungkan elemen sebelumnya ke elemen baru
    prev->next = baru;
    // pointer baru dibebaskan
    baru = NULL;
}

/* Menambah Kolom Setelah Kolom Tertentu */
void addAfterK(eKolom *prev, menuRestoran Menu) {
    eKolom *baru; // pointer bertipe elemen kolom
    baru = (eKolom *)malloc(sizeof(eKolom)); // meminta alokasi memori
    strcpy(baru->kontainer_kol.menu, Menu.menu); // masukan data
    baru->kontainer_kol.harga = Menu.harga; // masukan data
    if (prev->next_kol == NULL) {
        // jika dimasukan setelah elemen terakhir
        baru->next_kol = NULL;
    } else {
        // jika dimasukan di tengah
        baru->next_kol = prev->next_kol;
    }
    // menghubungkan elemen sebelumnya ke elemen baru
    prev->next_kol = baru;
    // pointer baru dibebaskan
    baru = NULL;
}

/* Menambah Baris di Akhir List */
void addLastB(restoran Resto, list *L) {
    if ((*L).first == NULL) {
        // jika list masih kosong, jalankan fungsi addFirst
        addFirstB(Resto, L);
    } else {
        // jika list sudah berisi, cari elemen terakhir
        eBaris *last = (*L).first;
        while (last->next != NULL) {
            // ditelusuri sampai next nya NULL
            last = last->next;
        }
        // jalankan fungsi addAfter (after elemen terakhir)
        addAfterB(last, Resto, L);
    }
}

/* Menambah Kolom di Akhir List Baris */
void addLastK(menuRestoran Menu, eBaris *L) {
    if ((*L).col == NULL) {
        // jika list baris masih kosong, jalankan fungsi addFirst
        addFirstK(Menu, L);
    } else {
        // jika list baris sudah berisi, cari elemen terakhir
        eKolom *last = (*L).col;
        while (last->next_kol != NULL) {
            // ditelusuri sampai next nya NULL
            last = last->next_kol;
        }
        // jalankan fungsi addAfter (after elemen terakhir)
        addAfterK(last, Menu);
    }
}

/* Menghapus Elemen Kolom Pertama List Baris */
void delFirstK(eBaris *L) {
    if ((*L).col != NULL) {
        // jika list baris tidak kosong
        eKolom *hapus = (*L).col; // pointer ke elemen pertama
        if (countElementK(*L) == 1) {
            // jika elemen kolom hanya 1
            (*L).col = NULL;
        } else {
            // jika elemen kolom lebih dari 1
            // pindahkan first ke elemen kedua
            (*L).col = (*L).col->next_kol;
            // putuskan hubungan elemen pertama dengan kedua
            hapus->next_kol = NULL;
        }
        // hapus elemen dari memori
        free(hapus);
    }
}

/* Menghapus Elemen Kolom Setelah Elemen Tertentu */
void delAfterK(eKolom *prev) {
    eKolom *hapus = prev->next_kol; // pointer ke elemen yg ingin dihapus
    if (hapus != NULL) {
        // jika elemen ada
        if (hapus->next_kol == NULL) {
            // jika elemen terakhir
            prev->next_kol = NULL;
        } else {
            // jika elemen di tengah
            // hubungkan prev dengan next elemen yg akan dihapus
            prev->next_kol = hapus->next_kol;
            // putuskan hubungan elemen yg ingin dihapus dengan elemen selanjutnya
            hapus->next_kol = NULL;
        }
        // hapus elemen dari memori
        free(hapus);
    }
}

/* Menghapus Elemen Kolom Terakhir */
void delLastK(eBaris *L) {
    if ((*L).col != NULL) {
        // jika kolom tidak kosong
        if (countElementK(*L) == 1) {
            // jika elemen hanya 1
            delFirstK(L);
        } else {
            // jika elemen lebih dari 1, cari elemen terakhir
            eKolom *last = (*L).col;
            eKolom *before_last;
            while (last->next_kol != NULL) {
                before_last = last;
                last = last->next_kol;
            }
            // jalankan delAfter elemen sebelum elemen terakhir
            delAfterK(before_last);
        }
    }
}

/* Menghapus Seluruh Elemen Kolom */
void delAllK(eBaris *L) {
    if (countElementK(*L) != 0) {
        // jika elemen kolom ada isinya
        for (int i = countElementK(*L); i >= 1; i--) {
            // hapus satu per satu dari belakang
            delLastK(L);
        }
    }
}

/* Menghapus Elemen Baris Pertama */
void delFirstB(list *L) {
    if ((*L).first != NULL) {
        // jika list tidak kosong
        eBaris *hapus = (*L).first; // pointer ke elemen pertama
        if (hapus->col != NULL) {
            // jika baris memiliki elemen kolom
            // hapus seluruh elemen kolom
            delAllK(hapus);
        }
        if (countElementB(*L) == 1) {
            // jika elemen baris hanya 1
            (*L).first = NULL;
        } else {
            // jika elemen kolom lebih dari 1
            // pindahkan first ke elemen kedua
            (*L).first = (*L).first->next;
        }
        // putuskan hubungan elemen pertama dengan kedua
        hapus->next = NULL;
        // hapus elemen dari memori
        free(hapus);
    } else {
        // jika list kosong
        printf("list kosong");
    }
}

/* Menghapus Elemen Baris Setelah Baris Tertentu */
void delAfterB(eBaris *prev) {
    if (prev != NULL) {
        // jika elemen sebelumnya ada
        eBaris *hapus = prev->next; // pointer ke elemen yg ingin dihapus
        if (hapus != NULL) {
            // jika elemen ada
            if (hapus->col != NULL) {
                // jika baris memiliki elemen kolom
                // hapus seluruh elemen kolom
                delAllK(hapus);
            }
            if (hapus->next == NULL) {
                // jika elemen terakhir
                prev->next = NULL;
            } else {
                // jika elemen di tengah
                // hubungkan prev dengan next elemen yg akan dihapus
                prev->next = hapus->next;
            }
            // putuskan hubungan elemen yg ingin dihapus dengan elemen selanjutnya
            hapus->next = NULL;
            // hapus elemen dari memori
            free(hapus);
        }
    }
}

/* Menghapus Elemen Kolom Terakhir */
void delLastB(list *L) {
    if ((*L).first != NULL) {
        // jika list tidak kosong
        if (countElementB(*L) == 1) {
            // jika elemen hanya 1
            delFirstB(L);
        } else {
            // jika elemen lebih dari 1
            // cari elemen terakhir
            eBaris *last = (*L).first;
            eBaris *before_last;
            while (last->next != NULL) {
                before_last = last;
                last = last->next;
            }
            // jalankan delAfter elemen sebelum elemen terakhir
            delAfterB(before_last);
        }
    }
}

/* Menghapus Seluruh Elemen Baris */
void delAllB(list *L) {
    if (countElementB(*L) != 0) {
        // jika list ada isinya
        for (int i = countElementB(*L); i >= 1; i--) {
            // hapus satu per satu dari belakang
            delLastB(L);
        }
    }
}

/* Mencetak Elemen Baris dan Kolom Satu Per Satu */
void printElement(list L) {
    if (L.first != NULL) {
        // jika list tidak kosong
        eBaris *bantu = L.first; // menunjuk ke baris pertama
        int i = 1; // membantu mencetak new line dan identifikasi baris keberapa
        while (bantu != NULL) {
            // jika elemen ada isinya
            printf("%s:\n", bantu->kontainer.nama); // cetak baris
            eKolom *eCol = bantu->col; // menunjuk ke kolom pertama
            while (eCol != NULL) {
                // jika kolom ada isinya
                printf("- %s %d\n",eCol->kontainer_kol.menu, eCol->kontainer_kol.harga); // cetak kolom
                eCol = eCol->next_kol; // majukan pointer penunjuk kolom
            }
            if(i < countElementB(L)) {
                // jika bukan elemen terakhir
                printf("\n");
            }
            bantu = bantu->next; // majukan pointer penunjuk baris
            i++;
        }
    } else {
        // jika list kosong
        printf("list kosong\n");
    }
}

/* Mengambil Alamat Baris Yang Dicari */
eBaris *getBaris(list L, char nama[]) {
    eBaris *bantu = L.first; // menunjuk ke baris pertama
    int found = 0; // penanda ditemukan
    while (bantu != NULL && found == 0) {
        // selama belum mencapai elemen akhir
        // dan baris yg dicari belum ditemukan
        if(strcmp(bantu->kontainer.nama,nama) == 0) {
            // jika ketemu, kembalikan alamat elemen
            found = 1;
            return bantu;
        }
        bantu = bantu->next;
    }
    return 0;
}

/* Mengambil Alamat Elemen Terakhir */
eKolom* getLastKolom(eBaris *L) {
    eKolom *last = (*L).col; // menunjuk ke kolom pertama
    while(last->next_kol != NULL) {
        // selama next elemen nya bukan null
        last = last->next_kol;
    }
    // kembalikan alamat elemen
    return last;
}

/* Memindahkan Menu dari Resto Kiri (A) ke Resto Kanan (B) */
void switchMenu(restoran restoA, restoran restoB, list *L) {
    // mencari alamat baris resto A dan resto B
    eBaris *barisRestoA = getBaris(*L, restoA.nama);
    eBaris *barisRestoB = getBaris(*L, restoB.nama);
    // mencari alamat kolom terakhir resto B
    eKolom *lastKolomRestoB = getLastKolom(barisRestoB);
    // menunjuk ke elemen pertama
    eKolom *menuTukar = barisRestoA->col;
    eKolom *prev = barisRestoA->col;

    int i = 1, found = 0; // penanda posisi baris dan ditemukan menu yg sesuai
    while(menuTukar != NULL && found == 0) {
        // selama belum mencapai akhir kolom
        // dan belum ditemukan menu yg sesuai
        if(strcmp(menuTukar->kontainer_kol.menu, restoA.menuSwitch) == 0 && i == 1) {
            // jika ditemukan menu yg sesuai pada kolom teratas (pertama)
            // addLastK(menuTukar->kontainer_kol, barisRestoB);
            // pointer first kolom dihubungkan ke elemen kedua
            barisRestoA->col = menuTukar->next_kol;
            lastKolomRestoB->next_kol = menuTukar;
            found = 1; // penanda ditemukan
            menuTukar->next_kol = NULL;
        } else if(strcmp(menuTukar->kontainer_kol.menu, restoA.menuSwitch) == 0 && i != 1) {
            // jika ditemukan menu yg sesuai bukan di kolom teratas (kedua dst)
            // addLastK(menuTukar->kontainer_kol, barisRestoB);
            // pointer lengan elemen sebelum elemen yg dicari
            // dihubungkan ke elemen setelah elemen yg dicari
            prev->next_kol = menuTukar->next_kol;
            lastKolomRestoB->next_kol = menuTukar;
            found = 1; // penanda
            menuTukar->next_kol = NULL;
        }
        if(found == 0) {
            prev = menuTukar; // inisialisasi elemen sebelum elemen yg dicari
            menuTukar = menuTukar->next_kol; // memajukan pointer ke elemen berikutnya
            i++; // penanda lokasi elemen (awal atau bukan)
        }
    }
}