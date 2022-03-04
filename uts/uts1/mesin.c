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
void addFirstB(char nama[], list *L) {
    eBaris* baru;
    baru = (eBaris*)malloc(sizeof(eBaris));
    // memasukan data baru
    strcpy(baru->kontainer.nama, nama);
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
void addFirstK(char menu[], char harga[], eBaris *L) {
    eKolom* baru;
    baru = (eKolom*)malloc(sizeof(eKolom));
    // memasukan data baru
    strcpy(baru->kontainer_kol.menu, menu);
    strcpy(baru->kontainer_kol.harga, harga);
    if((*L).col == NULL) {
        baru->next_kol = NULL;
    } else {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

/* Menambah Elemen Baris Setelah Elemen Tertentu */
void addAfterB(eBaris* prev, char nama[], list *L) {
    eBaris* baru;
    baru = (eBaris*)malloc(sizeof(eBaris));
    // memasukan data
    strcpy(baru->kontainer.nama, nama);
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
void addAfterK(eKolom* prev, char menu[], char harga[]) {
    eKolom* baru;
    baru = (eKolom*)malloc(sizeof(eKolom));
    // memasukan data
    strcpy(baru->kontainer_kol.menu, menu);
    strcpy(baru->kontainer_kol.harga, harga);
    if(prev->next_kol == NULL) {
        baru->next_kol = NULL;
    } else {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL;
}

/* Menambah Baris di Akhir List */
void addLastB(char nama[], list *L) {
    if((*L).first == NULL) {
        // jika list masih kosong
        addFirstB(nama, L);
    } else {
        // jika list sudah ada isinya
        // cari baris terakhir
        eBaris *last = (*L).first;
        while(last->next != NULL) {
            last = last->next;
        }
        addAfterB(last, nama, L);
    }
}

/* Menambah Elemen Kolom di Akhir Kolom Suatu Baris */
void addLastK(char menu[], char harga[], eBaris *L) {
    if((*L).col == NULL) {
        // jika kolom kosong
        addFirstK(menu, harga, L);
    } else {
        // jika kolom sudah ada isinya
        // cari kolom terakhir
        eKolom *last = (*L).col;
        while(last->next_kol != NULL) {
            last = last->next_kol;
        }
        addAfterK(last, menu, harga);
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
            printf("%s:\n", bantu->kontainer.nama);
            eKolom* eCol = bantu->col;
            while(eCol != NULL) {
                // mencetak kolom
                printf("- %s %s\n", eCol->kontainer_kol.menu, eCol->kontainer_kol.harga);
                eCol = eCol->next_kol;
            }
            if(i < countElementB(L)) printf("\n");
            bantu = bantu->next;
            i = i + 1;
        }
    } else {
        // jika list kosong
        printf("list kosong\n");
    }
}

eBaris* getLatestBaris(list L, char nama[]){
	/*inisialisasi dan cek jika listnya tidak kosong, nilai tunjuk jadi elemen baris pertama*/
	eBaris* tunjuk = NULL;
	if (L.first != NULL)
	{
		tunjuk = L.first;
		/*perulangan selama bukan null dan bukan nama yang dicari*/
		while((tunjuk != NULL) && (strcmp(tunjuk->kontainer.nama, nama) != 0)) {
		    tunjuk = tunjuk->next;
		}
	}

	return tunjuk;
}

eKolom* getKolom(eBaris *L, char menu[]) {
    // printf("getkolom\n");
    /*eKolom* eCol = L->col;
    eKolom* prev;
    if(strcmp(eCol->kontainer_kol.menu, menu) == 0) {
        L->col = eCol->next_kol;
    }
    while(eCol != NULL) {
        // mencetak kolom
        if(strcmp(eCol->next_kol->kontainer_kol.menu, menu) == 0) {
            prev = eCol;
        }
        eCol = eCol->next_kol;
    }
    return prev;
    */
    eKolom *last = (*L).col;
    while(last->next_kol != NULL && strcmp(last->next_kol->kontainer_kol.menu, menu) != 0) {
        last = last->next_kol;
    }
    return last;
}

eBaris* getBaris(list *L, char resto[]) {
    // printf("getbaris\n");
    if((*L).first != NULL) {
        eBaris* baris = (*L).first;
        eBaris *res1;
        while(baris != NULL && strcmp(baris->kontainer.nama, resto) != 0) {
            // mencetak baris
            baris = baris->next;
        }
        return baris;
    }
}

eBaris *tunjukBaris(list L, char nama[]) {
    eBaris *bantu;
    bantu = L.first;
    int cek = 0;
    /* kondisi untuk perulangan sampai List baris terakhir */
    while (bantu != NULL && cek == 0)
    {
        /* kondisi jika tahun yang ada pda parameter == tahun yang ada pada list baris */
        if(strcmp(bantu->kontainer.nama,nama) == 0) {
            cek = 1;
            return bantu;
        }
        bantu = bantu->next;
    }
    
    return NULL;
}

eKolom* getLastKolom(eBaris *L) {
    // printf("getlastkolom\n");
    eKolom *last = (*L).col;
    while(last->next_kol != NULL) {
        last = last->next_kol;
    }
    return last;
}

void SwitchMenu(char resto1[], char menu[], char resto2[], list *L) {
    // mencari baris resto 1
    eBaris* barisResto1 = getBaris(L, resto1);
    // mencari prev menu yg dicari
    eKolom* prevmenuYgDitukar = getKolom(barisResto1, menu);
    // mencari baris resto 2
    eBaris* barisResto2 = getBaris(L, resto2);
    // next menu terakhir resto 2 menunjuk ke menu yg dicari
    addLastK(prevmenuYgDitukar->next_kol->kontainer_kol.menu, prevmenuYgDitukar->next_kol->kontainer_kol.harga, barisResto2);
    // next prev menu yg dicari pindah ke next menu
    prevmenuYgDitukar->next_kol = prevmenuYgDitukar->next_kol->next_kol;
}
/*
void switchMenu(restoran masukanDari, restoran masukanKe, list *L) {
    
    eBaris *rowDari = tunjukBaris(*L, masukanDari.nama);
    eBaris *rowKe = tunjukBaris(*L, masukanKe.nama);
    eKolom *colDari = rowDari->col;
    eKolom *prev = rowDari->col;
    int itr = 1;
    int cek = 0;

    //perualangan 
    while(colDari != NULL && cek == 0) {
        //kondisi jika menu yang akan dipindah terletak di awal kolom
        if(itr==1 && strcmp(colDari->kontainer_kol.menu, masukanDari.nama) == 0 ) {
            addLastK(colDari->kontainer_kol.menu, colDari->kontainer_kol.harga, rowKe);
            delFirstK(rowDari);
            cek = 1;
        } 
        //kondisi jika menu yang akan dipindah terletak bukan di awal kolom
        else if(strcmp(colDari->kontainer_kol.menu, masukanDari.nama) == 0 && itr != 1) {
            addLastK(colDari->kontainer_kol.menu, colDari->kontainer_kol.harga, rowKe);
            delAfterK(prev);
            cek = 1;
        }
        //memasukan nilai prev dan colDari yang baru
        prev = colDari;
        colDari = colDari->next_kol;
        itr++;
    }
}
*/