#include "header.h"

int main(){
    list resto1, resto2, menuSwap;
    createList(&resto1), createList(&resto2), createList(&menuSwap);
    int n1 = 0, n2 = 0, m = 0;
    char makanan[50], harga[50];
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%s%s", makanan, harga);
        addLast(makanan, harga, &resto1);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%s%s", makanan, harga);
        addLast(makanan, harga, &resto2);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s%s", makanan, harga);
        addLast(makanan, harga, &menuSwap);
    }
    tukarMenu(&resto1, &resto2, &menuSwap);
    printf("menu warung pertama:\n");
    printElement(resto1);
    printf("\nmenu warung kedua:\n");
    printElement(resto2);
    return 0;
}