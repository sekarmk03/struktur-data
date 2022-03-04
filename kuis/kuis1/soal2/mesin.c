#include "header.h"

/* Membuat kerangka list */
void createList(list *L){
    /* 
        Membuat list sesuai kata maks elemen
        Menginisialisasi pointer next dan prev -2
        yang artinya elemen tersebut masih kosong
    */
    (*L).first = -1;
    (*L).tail = -1;
    int i;
    for(i = 0; i < 20; i++){
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

/* Menghitung elemen list */
int countElement(list L){
    int hasil = 0;
    if(L.first != -1){
        int bantu = 0;
        bantu = L.first;
        while(bantu != -1){
        // selama pointer bantu bukan -1
        // ada elemen
            hasil++;
            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

/* Menegecek elemen yg kosong */
int emptyElement(list L){
    /*
        Mencari elemen kosong
        Menyimpan indeks yang kosong
        (yang pointer next nya -2)
        lalu dikembalikan
    */
    int hasil = -1;
    if(countElement(L) < 20){
        int ketemu = 0;
        int i = 0;
        while((ketemu == 0) && (i < 20)){
            if(L.data[i].next == -2){
                hasil = i;
                ketemu = 1;
            } else {
                i++;
            }
        }
    }
    return hasil;
}

/* Menambah elemen di awal */
void addFirst(char kata[], list *L){
    // jika kata elemen belum maksimal
    if(countElement(*L) < 20){
        // mencari letak elemen kosong
        int baru = emptyElement(*L);
        // memasukkan data
        strcpy((*L).data[baru].kontainer.kata, kata);
        if((*L).first == -1){
            // jika elemen pertama
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        } else {
            // jika bukan elemen pertama
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }
        (*L).first = baru;
    } else {
        // jika elemen mencapai batas maksimal (sudah terisi semua)
        printf("Sudah tidak dapat ditambah\n");
    }
}

/* Menambah elemen di tengah */
void addAfter(int before, char kata[], list *L){
    // jika kata elemen belum maksimal
    if(countElement(*L) < 20){
        // mencari letak elemen kosong
        int baru = emptyElement(*L);
        // memasukkan data
        strcpy((*L).data[baru].kontainer.kata, kata);
        if((*L).data[before].next != -1){
            // jika ditambah setelah elemen pertama
            (*L).data[baru].prev = before;
            (*L).data[baru].next = (*L).data[before].next;
            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].prev = baru;
        } else {
            // jika ditambah setelah elemen tertentu
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    } else {
        // jika elemen mencapai batas maksimal (sudah terisi semua)
        printf("Sudah tidak dapat ditambah\n");
    }
}

/* Menambah elemen di akhir */
void addLast(char kata[], list *L){
    if((*L).first == -1){
        // jika list masih kosong
        addFirst(kata, L);
    } else {
        // jika list sudah terisi
        addAfter((*L).tail, kata, L);
    }
}

/* Menghapus elemen pertama */
void delFirst(list *L){
    if((*L).first != -1){
        // jika list ada isinya
        int hapus = (*L).first;
        if(countElement(*L) == 1){
            // jika elemen hanya 1
            (*L).first = -1;
            (*L).tail = -1;
        } else {
            // jika elemen > 1
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        // mengosongkan elemen
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    } else {
        // jika list kosong
        printf("List kosong\n");
    }
}

/* Menghapus elemen di tengah */
void delAfter(int before, list *L){
    int hapus = (*L).data[before].next;
    if(hapus != -1){
        // jika before bukan elemen terakhir
        if((*L).data[hapus].next == -1){
            // jika menghapus elemen terakhir
            (*L).tail = before;
            (*L).data[before].next = -1;
        } else {
            // jika menghapus elemen setelah elemen tertentu
            (*L).data[before].next = (*L).data[hapus].next;
            (*L).data[(*L).data[hapus].next].prev = before;
        }
        // mengosongkan elemen
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
}

/* Menghapus elemen terakhir */
void delLast(list *L){
    if((*L).first != -1){
        // jika list tidak kosong
        if(countElement(*L) == 1){
            // jika elemen hanya 1
            delFirst(L);
        } else {
            // jika elemen > 1
            delAfter((*L).data[(*L).tail].prev, L);
        }
    } else {
        // jika list kosong
        printf("List kosong\n");
    }
}

/* Menghapus semua elemen */
void delAll(list *L){
    int i = 0;
    for(i = countElement(*L); i >= 1; i--){
        // hapus semua elemen dari belakang
        delLast(L);
    }
}

/* Mencetak semua elemen */
void printElement(list L, int n){
    if(L.first != -1){
        // jika list tidak kosong
        int bantuDepan = L.first; // dari depan
        int bantuBelakang = L.tail; // dari belakang
        int i = 1;
        for (i = 1; i <= n; i++) {
            int tunjuk = L.tail; // dari belakang
            while (tunjuk != bantuBelakang) {
                // mencetak spasi sampai tunjuk == pointer bantu belakang
                int len = strlen(L.data[tunjuk].kontainer.kata);
                for (int j = 0; j < len; j++) {
                    printf(" ");
                }
                tunjuk = L.data[tunjuk].prev;
            }
            // tunjuk melompati pointer bantu belakang kearah depan
            tunjuk = L.data[tunjuk].prev;
            printf("%s", L.data[bantuBelakang].kontainer.kata);
            if(i != n) {
                // jika i tidak sama dengan n
                while (tunjuk != bantuDepan){
                    // mencetak spasi sampai tunjuk == pointer bantu depan
                    int len = strlen(L.data[tunjuk].kontainer.kata);
                    int j = 0;
                    for (j = 0; j < len; j++) {
                        printf(" ");
                    }
                    tunjuk = L.data[tunjuk].prev;
                }
            }
            if(bantuBelakang != bantuDepan){
                // jika pointer bantu belakang dan depan tidak sama
                printf("%s", L.data[bantuDepan].kontainer.kata);
            }
            if(i != n){
                // jika i tidak sama dengan n
                tunjuk = L.data[tunjuk].prev;
                bantuBelakang = L.data[bantuBelakang].prev;
                bantuDepan = L.data[bantuDepan].next;
            }
            printf("\n");
        }
    } else {
        // jika list kosong
        printf("List kosong\n");
    }
}

/* Mencetak semua elemen dari belakang */
void printElementReverse(list L){
    if(L.first != -1){
        // jika list tidak kosong
        int bantu = L.tail; // dari belakang
        int i = 1;
        while (bantu != -1){
            // cetak sampai elemen pertama dari belakang
            printf("%s\n", L.data[bantu].kontainer.kata);
            bantu = L.data[bantu].prev;
            i++;
        }
        printf("========\n");
    } else {
        // jika list kosong
        printf("List kosong\n");
    }
}