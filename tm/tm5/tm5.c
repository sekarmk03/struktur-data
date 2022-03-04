#include "header.h"

int main() {
    list L1, L2;
    createList(&L1), createList(&L2);
    int n = 0;
    char nama[50], tahun[50], pemain[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s", nama, tahun);
        if(i != 0) {
            eBaris *baris = sortDinamyc(&L2, nama, tahun);
        } else {
            addFirstB(nama, tahun, &L2);
        }
        // scanf("%s", pemain);
        // addLastK(pemain, baris);
        // scanf("%s", pemain);
        // addFirstK(pemain, baris);
        // scanf("%s", pemain);
        // addAfterK(baris->col, pemain);
        // scanf("%s", pemain);
        // addLastK(pemain, baris);
    }
    
    printElement(L2);
    // printElement(L1);
    /*
    printf("=================\n");
    addFirstB("1", "Orang_1", &L);
    addFirstK("IF40K1", "A", L.first);
    addAfterK(L.first->col, "IF40Z1", "A");
    addLastK("IF40Z2", "A", L.first);
    addAfterB(L.first, "2", "Orang_2");
    addFirstK("TI5141", "A", L.first->next);
    addLastK("IF5021", "A", L.first->next);
    addLastB("3", "Orang_3", &L);
    addFirstK("IF5321", "A", L.first->next->next);
    printElement(L);
    printf("=================\n");
    delAllB(&L);
    printElement(L);
    printf("=================\n");
    */
    return 0;
}