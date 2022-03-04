#include "header.h"

int main(){
    // buat variabel
    list listBarang;
    char nama[50], type[10];
    int kode, harga;
    char by;
    createList(&listBarang); // buat kerangka list
    do {
        scanf("%s", nama);
        if(strcmp(nama, "---") != 0) {
            // jika masukan bukan ---
            scanf("%d%d", &harga, &kode); // masukkan masukan selanjutnya
            if(kode % 2 == 0) {
                // jika kode barang genap atau tidak ganjil
                // tambahkan elemen ke awal list
                addFirst(nama, harga, kode, &listBarang); //----------------> tambah 1 elemen di awal list L
            }
        }
        // diulang sampai masukan bukan ---
    } while (strcmp(nama, "---") != 0);
    scanf(" %c%s", &by, type);
    sortList(&listBarang, type, by); // mengurutkan elemen list barang berdasarkan tipe sort dan atributnya
    printElement(listBarang); // mencetak daftar barang setelah di urutkan
    return 0;
}