#include "header.h"

int main(){
    // deklarasi variable
    list L;
    char name[50], formula[50], concent[50];
    createList(&L); //--------------------------------------> buat kerangka list L
    scanf("%s%s%s", name, formula, concent);
    addFirst(name, formula, concent, &L); //----------------> tambah 1 elemen di awal list L
    scanf("%s%s%s", name, formula, concent);
    addLast(name, formula, concent, &L); //-----------------> tambah 1 elemen di akhir list L
    scanf("%s%s%s", name, formula, concent);
    addAfter(L.first->next, name, formula, concent, &L); //-> tambah 1 elemen setelah elemen kedua list L (elemen ke-3)
    printf("======\n");
    printElement(L); //-------------------------------------> cetak elemen list L
    delFirst(&L); //----------------------------------------> hapus elemen pertama list L
    scanf("%s%s%s", name, formula, concent);
    addLast(name, formula, concent, &L); //-----------------> tambah 1 elemen di akhir list L
    delAfter(L.first->next, &L); //-------------------------> hapus 1 elemen setelah elemen ke-2 (elemen ke-3)
    printElement(L); //-------------------------------------> cetak elemen list L
    delLast(&L); //-----------------------------------------> hapus 1 elemen terakhir list L
    scanf("%s%s%s", name, formula, concent);
    addFirst(name, formula, concent, &L); //----------------> tambah 1 elemen di awal list L
    printElement(L); //-------------------------------------> cetak elemen list L
    delAll(&L); //------------------------------------------> hapus semua elemen list L
    printElement(L); //-------------------------------------> cetak elemen list L
    scanf("%s%s%s", name, formula, concent);
    addLast(name, formula, concent, &L); //-----------------> tambah 1 elemen di akhir list L
    printElement(L); //-------------------------------------> cetak elemen list L
    return 0;
}
