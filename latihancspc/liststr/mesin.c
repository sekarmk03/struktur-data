#include "header.h"

/* prosedur membuat list baru
   membuat pointer first untuk
   menunjuk ke elemen pertama list */
void createList(list *L) {
    (*L).first = NULL;
}

/* prosedur menghitung jumlah elemen */
int countElement(list L) {
    int count = 0;
    if(L.first != NULL) {
        // jika bukan list kosong
        element* flag; // pointer penunjuk elemen
        flag = L.first;
        while(flag != NULL) {
            // selama masih ada elemen yg ditunjuk
            count++;
            flag = flag->next;
        }
    }
    return count;
}

/* prosedur menambah 1 elemen di awal list */
void addFirst(char str[], list *L) {
    element *new; // pointer penunjuk elemen baru
    new = (element*)malloc(sizeof(element)); // membuat elemen baru
    // mengisi elemen baru dgn data parameter
    strcpy(new->container.str, str);
    new->next = (*L).first; // pointer next elemen baru menunjuk ke elemen milik pointer first
    (*L).first = new; // pointer first diinisialisasi oleh elemen baru
    new = NULL; // mengosongkan pointer baru
}

/* prosedur menambah 1 elemen setelah elemen tertentu
   yg ditandai oleh pointer prev */
void addAfter(element* prev, char str[], list *L) {
    element *new;
    new = (element*)malloc(sizeof(element));
    strcpy(new->container.str, str);
    if(prev->next == NULL) {
        // jika elemen baru akan ditambah setelah elemen terakhir
        new->next = NULL;
    } else {
        // jika elemen baru ditambah di tengah2
        // pointer next elemen baru menunjuk ke elemen yg ditunjuk pointer next elemen prev
        new->next = prev->next;
    }
    prev->next = new; // pointer next elemen prev menunjuk ke elemen baru
    new = NULL;
}

/* prosedur menambah 1 elemen di akhir list */
void addLast(char str[], list *L) {
    if((*L).first == NULL) {
        // jika list kosong jalankan prosedur addFirst()
        addFirst(str, L);
    } else {
        // jika list tidak kosong cari elemen terakhir
        element *prev = (*L).first;
        while(prev->next != NULL) {
            prev = prev->next;
        }
        // tambahkan elemen baru setelah elemen terakhir
        // dgn prosedur addAfter()
        addAfter(prev, str, L);
    }
}

/* prosedur menghapus 1 elemen pertama list */
void delFirst(list *L) {
    if((*L).first != NULL) {
        // jika ada elemen yg dihapus/list tidak kosong
        element *del = (*L).first; // pointer del menunjuk ke elemen pertama
        if(countElement(*L) == 1) {
            // jika elemen hanya 1
            (*L).first = NULL;
        } else {
            // jika elemen > 1
            // pindahkan pointer first ke elemen kedua
            (*L).first = (*L).first->next;
            del->next = NULL; // null kan pointer del next
        }
        free(del); // bebaskan del
    }
}

/* prosedur menghapus 1 elemen setelah elemen tertentu */
void delAfter(element *prev, list *L) {
    element *del = prev->next; // pointer del menunjuk elemen setelah elemen yg ditunjuk pointer prev next
    if(del != NULL) {
        // jika yg ditunjuk ada elemennya
        prev->next = del->next; // pointer prev next menunjuk elemen yg ditunjuk pointer del next
        del->next = NULL; // pointer del dibuat null
        free(del); // elemen del dibebaskan
    }
}

/* prosedur menghapus 1 elemen di akhir list */
void delLast(list *L) {
    if((*L).first != NULL) {
        // jika list ada isinya
        if(countElement(*L) == 1) {
            // jika elemen hanya 1
            delFirst(L);
        } else {
            element *last = (*L).first, *prev;
            while(last->next != NULL) {
                // mencari prev elemen terakhir
                prev = last;
                last = last->next;
            }
            // dihapus dgn prosedur delAfter()
            delAfter(prev, L);
        }
    }
}

/* prosedur menghapus seluruh elemen dalam list */
void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for (i = countElement(*L); i >= 1; i--) {
            // hapus elemen dari belakang
            delLast(L);
        }
    }
}

/* prosedur mencetak seluruh elemen list */
void printElement(list L) {
    if(L.first != NULL) {
        // jika list ada isinya
        element *flag = L.first; // untuk menunjuk tiap elemen
        int i = 1;
        while(flag != NULL) {
            // cetak isi elemen yg ditunjuk pointer flag
            printf("%s\n", flag->container.str);
            flag = flag->next;
            i++;
        }
    } else {
        // jika list kosong
        printf("list kosong\n");
    }
}