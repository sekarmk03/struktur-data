#include "header.h"

void createList(list *L) {
    (*L).first = -1;
    int i = 0;
    for ( i = 0; i < n; i++) {
        (*L).data[i].next = -2;
    }
}

int countElement(list L) {
    int hasil = 0;
    if(L.first != -1){
        int hitung = 0;
        hitung = L.first;
        while (hitung != -1) {
            hasil++;
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

int emptyElement(list L) {
    int hasil = -1;
    if(countElement(L) < n) {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < n)) {
            if(L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            } else {
                i++;
            }
        }
    }
    return hasil;
}

void addFirst(float bil, list *L) {
    if(countElement(*L) < n) {
        int baru = emptyElement(*L);
        (*L).data[baru].bil.bilFloat = bil;
        if((*L).first == -1) {
            (*L).data[baru].next = -1;
        } else {
            (*L).data[baru].next = (*L).first;
        }
        (*L).first = baru;
    } else {
        printf("List sudah tidak dapat ditambah\n");
    }
}

void addAfter(int prev, float bil, list *L) {
    if(countElement(*L) < n) {
        int baru = emptyElement(*L);
        (*L).data[baru].bil.bilFloat = bil;
        if((*L).data[prev].next == -1) {
            (*L).data[baru].next = -1;
        } else {
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    } else {
        printf("List sudah tidak dapat ditambah\n");
    }
}

void addLast(float bil, list *L) {
    if((*L).first == -1) {
        addFirst(bil, L);
    } else {
        if(countElement(*L) < 10) {
            int prev = (*L).first;
            while((*L).data[prev].next != -1) {
                prev = (*L).data[prev].next;
            }
            addAfter(prev, bil, L);
        } else {
            printf("List sudah tidak dapat ditambah\n");
        }
    }
}

void delFirst(list *L) {
    if((*L).first != -1) {
        int hapus = (*L).first;
        if(countElement(*L) == 1) {
            (*L).first = -1;
        } else {
            (*L).first = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    } else {
        printf("List kosong\n");
    }
}

void delAfter(int prev, list *L) {
    int hapus = (*L).data[prev].next;
    if(hapus != -1) {
        if((*L).data[hapus].next == -1) {
            (*L).data[prev].next = -1;
        } else {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L) {
    if((*L).first != -1) {
        if(countElement(*L) == 1) {
            delFirst(L);
        } else {
            int hapus = (*L).first;
            int prev = 0;
            while((*L).data[hapus].next != -1) {
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            delAfter(prev, L);
        }
    } else {
        printf("List kosong\n");
    }
}

void delAll(list *L) {
    int i = 0;
    for (i = countElement(*L); i >= 1; i--) {
        delLast(L);
    }
}

void printElement(list L) {
    if(L.first != -1) {
        int tunjuk = L.first;
        int i = 0;
        while(tunjuk != -1) {
            printf("%0.2f\n", L.data[tunjuk].bil.bilFloat);
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    } else {
        printf("List kosong\n");
    }
}
