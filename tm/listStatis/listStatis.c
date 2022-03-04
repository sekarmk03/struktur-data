#include "header.h"

int main() {
    list L;
    n = 0;
    scanf("%d", &n);
    createList(&L);
    int i = 0;
    for (i = 0; i < n; i++) {
        float bil = 0;
        scanf("%f", &bil);
        addFirst(bil, &L);
    }
    printElement(L);
    return 0;
}
