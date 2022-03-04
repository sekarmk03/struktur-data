#include "header.h"

int main() {
    queue Q1, Q2;
    createEmpty(&Q1);
    createEmpty(&Q2);
    char nama[100], ktp[100];
    int n = 0, m = 0, priority = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s%d", nama, ktp, &priority);
        addPriority(nama, ktp, priority, &Q1);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int jml = 0;
        scanf("%d", &jml);
        printQueue(&Q1, jml, i+1);
    }
    printQueue(&Q1, countElement(Q1) + 1, 0);
    return 0;
}