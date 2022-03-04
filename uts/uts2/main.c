#include "header.h"
int main() {
    list L; // membuat list
    createList(&L); // membuat list di memori
    restoran Resto, restoA, restoB; // penampung data restoran (baris)
    menuRestoran masukanMenu; // penampung data menu (kolom)

    int n = 0; // jumlah baris
    scanf("%d", &n);
    
    char startSwitch[20]; // penanda start dan switch

    for(int i = 0; i < n; i++) {
        scanf("%s", startSwitch); // penanda start
        if(strcmp(startSwitch, "start") == 0) {
            // jika penanda berisi start
            scanf("%s", Resto.nama); // masukan data restoran (baris)
            addLastB(Resto, &L); // memasukan data sebagai elemen terakhir
            // jika masukan pertama maka alamatnya menunjuk ke baris pertama
            // jika bukan masukan pertama maka digeser ke kanan
            eBaris* baris = i == 0 ? L.first : baris->next; // alamat baris saat ini
            do {
                scanf("%s", masukanMenu.menu); // masukan nama menu
                if(strcmp(masukanMenu.menu, "end") != 0) {
                    // jika nama menu tidak berisi "end"
                    scanf("%d", &masukanMenu.harga); // masukan harga menu
                    addLastK(masukanMenu, baris); // memasukan data menu sebagai elemen kolom terakhir
                }
                // diulang selama nama menu bukan "end"
            }while(strcmp(masukanMenu.menu, "end") != 0);
        }
    }
    
    scanf("%s", startSwitch); // penanda switch

    do {
        scanf("%s", restoA.nama); // masukan data resto asal (resto A atau resto Kiri)
        if(strcmp(restoA.nama, "end") != 0) {
            // jika resto asal tidak berisi "end"
            scanf("%s%s", restoA.menuSwitch, restoB.nama); // masukan menu yang ingin ditukar dan resto tujuan
            switchMenu(restoA, restoB, &L); // tukar menu dari resto asal ke tujuan
        }
        // diulang selama resto asal bukan "end"
    } while(strcmp(restoA.nama, "end") != 0);

    printElement(L); // mencetak elemen

    return 0;
}