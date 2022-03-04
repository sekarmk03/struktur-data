#include "header.h"

int main(){
    // membuat list
    list susunKata;
    createList(&susunKata);
    int n = 0;
    char kata[100];
    scanf("%d", &n);
    // memasukkan elemen ke list
    for (int i = 0; i < n; i++) {
        scanf("%s", kata);
        addLast(kata, &susunKata);
    }
    // menghitung jumlah baris
    int x = n / 2;
    if(n % 2 == 1){
        x += 1;
    }
    // mencetak isi list berdasarkan spesifikasi
    printElement(susunKata, x);
    return 0;
}