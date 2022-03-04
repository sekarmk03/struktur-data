#include "header.h"

void createEmpty(stack *S) {
    (*S).top = -1;
}

int isEmpty(stack S) {
    int hasil = 0;
    if(S.top == -1) {
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S) {
    int hasil = 0;
    if(S.top == 9) {
        hasil = 1;
    }
    return hasil;
}

void push(char nama[], char harga[], stack *S) {
    if(isFull(*S) == 1) {
        printf("Stack penuh\n");
    } else {
        if(isEmpty(*S) == 1) {
            (*S).top = 0;
            strcpy((*S).data[0].nama, nama);
            strcpy((*S).data[0].harga, harga);
        } else {
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].nama, nama);
            strcpy((*S).data[(*S).top].harga, harga);
        }
    }
}

void pop(stack *S) {
    if((*S).top == 0) {
        (*S).top = -1;
    } else {
        if((*S).top != -1) {
            (*S).top = (*S).top - 1;
        }
    }
}

void popPush(stack *S1, stack *S2) {
    if((*S1).top == 0) {
        push((*S1).data[0].nama, (*S1).data[0].harga, S2);
        (*S1).top = -1;
    } else {
        if((*S1).top != -1) {
            push((*S1).data[(*S1).top].nama, (*S1).data[(*S1).top].harga, S2);
            (*S1).top = (*S1).top - 1;
        }
    }
}

void printStack(stack S, char nStack[]) {
    printf("%s:\n", nStack);
    if(S.top != -1) {
        int i, j = 1;
        for(i = S.top; i >= 0; i--) {
            printf("%d. %s\n", j, S.data[i].nama);
            j++;
        }
    } else {
        printf("- Stack Kosong\n");
    }
}