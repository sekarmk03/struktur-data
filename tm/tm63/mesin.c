#include "header.h"

void createEmpty(stack *S) {
    (*S).top = NULL;
}

int isEmpty(stack S) {
    int hasil = 0;
    if(S.top == NULL) {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S) {
    int hasil = 0;
    if(S.top != NULL) {
        elemen* bantu;
        bantu = S.top;
        while(bantu != NULL) {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(char nama[], char harga[], stack *S) {
    elemen* baru;
    baru = (elemen*)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.harga, harga);
    if((*S).top == NULL) {
        baru->next = NULL;
    } else {
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S) {
    if((*S).top != NULL) {
        elemen *hapus = (*S).top;
        if(countElement(*S) == 1) {
            (*S).top = NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    } else {
        printf("- Stack Kosong\n");
    }
}

void popPush(stack *S1, stack *S2) {
    if((*S1).top != NULL) {
        elemen *hapus = (*S1).top;
        push(hapus->kontainer.nama, hapus->kontainer.harga, S2);
        if(countElement(*S1) == 1) {
            (*S1).top = NULL;
        } else {
            (*S1).top = (*S1).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    } else {
        printf("- Stack Kosong\n");
    }
}

void printStack(stack S, char nStack[]) {
    printf("%s:\n", nStack);
    if(S.top != NULL) {
        elemen* bantu = S.top;
        int i = 1;
        while(bantu != NULL) {
            printf("%d. %s\n", i, bantu->kontainer.nama);
            bantu = bantu->next;
            i++;
        }
    } else {
        printf("- Stack Kosong\n");
    }
}