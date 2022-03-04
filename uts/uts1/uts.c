#include "header.h"

int main() {
    list L; // deklarasi list
    createList(&L); // membuat list
    int n = 0; // jumlah masukan baris
    char nama[200], menu[200], harga[200], startSwitch[50]; // masukan
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", startSwitch);
        if(strcmp(startSwitch, "start") == 0) {
            scanf("%s", nama);
            addLastB(nama, &L);
            // eBaris *baris = i == 0 ? L.first : baris->next;
            eBaris *baris = getLatestBaris(L, nama);
            do {
                scanf("%s", menu);
                if(strcmp(menu, "end") != 0) {
                    scanf("%s", harga);
                    addLastK(menu, harga, baris);
                }
            } while (strcmp(menu, "end") != 0);
        }
    }
    char resto1[200], menuSwitch[200], resto2[200];
    scanf("%s", startSwitch);
    do {
        scanf("%s", resto1);
        if(strcmp(resto1, "end") != 0) {
            scanf("%s%s", menuSwitch, resto2);
            SwitchMenu(resto1, menuSwitch, resto2, &L);
        }
    } while (strcmp(resto1, "end") != 0);
    printElement(L); // mencetak list
    return 0;
}