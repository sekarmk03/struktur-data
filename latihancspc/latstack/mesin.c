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

void push(int index, char tanda, stack *S) {
    if(isFull(*S) == 1) {
        printf("Stack penuh\n");
    } else {
        if(isEmpty(*S) == 1) {
            (*S).top = 0;
            (*S).data[0].tanda = tanda;
            (*S).data[0].index = index;
        } else {
            (*S).top = (*S).top + 1;
            (*S).data[(*S).top].tanda = tanda;
            (*S).data[(*S).top].index = index;
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

void moveElStack(stack *S1, stack *S2) {
    if((*S1).top != -1) {
        int i;
        for(i = (*S1).top; i >= 0; i--) {
            if((*S1).top == 0) {
                if(((*S1).data[0].tanda == '(') || ((*S1).data[0].tanda == ')') ||
                ((*S1).data[0].tanda == '{') || ((*S1).data[0].tanda == '}') ||
                ((*S1).data[0].tanda == '[') || ((*S1).data[0].tanda == ']')) {
                    push((*S1).data[0].index, (*S1).data[0].tanda, S2);
                }
                (*S1).top = -1;
            } else {
                if((*S1).top != -1) {
                    if(((*S1).data[(*S1).top].tanda == '(') || ((*S1).data[(*S1).top].tanda == ')') ||
                    ((*S1).data[(*S1).top].tanda == '{') || ((*S1).data[(*S1).top].tanda == '}') ||
                    ((*S1).data[(*S1).top].tanda == '[') || ((*S1).data[(*S1).top].tanda == ']')) {
                        push((*S1).data[(*S1).top].index, (*S1).data[(*S1).top].tanda, S2);
                    }
                    (*S1).top = (*S1).top - 1;
                }
            }
        }
    }
}

void printStack(stack S) {
    if(S.top != -1) {
        int i;
        for(i = 0; i <= S.top; i++) {
            if((S.data[i].tanda == '(') || (S.data[i].tanda == ')') ||
                (S.data[i].tanda == '{') || (S.data[i].tanda == '}') ||
                (S.data[i].tanda == '[') || (S.data[i].tanda == ']')) {
                printf("%d %c\n", S.data[i].index, S.data[i].tanda);
            }
        }
        /*for(i = S.top; i >= 0; i--) {
            if((S.data[i].tanda == '(') || (S.data[i].tanda == ')') ||
                (S.data[i].tanda == '{') || (S.data[i].tanda == '}') ||
                (S.data[i].tanda == '[') || (S.data[i].tanda == ']')) {
                printf("%d %c\n", S.data[i].index, S.data[i].tanda);
            }
        }*/
    } else {
        printf("- Stack Kosong\n");
    }
}

void cekPair(int index, char tanda, stack *S) {
    if(tanda == ')') {
        if((*S).data[(*S).top].tanda == '(') {
            pop(S);
        } else {
            push(index, tanda, S);
        }
    } else if(tanda == '}') {
        if((*S).data[(*S).top].tanda == '{') {
            pop(S);
        } else {
            push(index, tanda, S);
        }
    } else if(tanda == ']') {
        if((*S).data[(*S).top].tanda == '[') {
            pop(S);
        } else {
            push(index, tanda, S);
        }
    } else {
        push(index, tanda, S);
    }
}