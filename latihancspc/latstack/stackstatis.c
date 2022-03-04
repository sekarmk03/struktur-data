#include "header.h"

int main() {
    stack S1, S2;
    createEmpty(&S1);
    createEmpty(&S2);
    char tanda;
    int n = 0, index = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &index, &tanda);
        cekPair(index, tanda, &S1);
    }
    // moveElStack(&S1, &S2);
    printStack(S1);
    return 0;
}