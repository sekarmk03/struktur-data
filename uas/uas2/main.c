#include "header.h"

int main(){
    // deklarasi graph
    graph G;
    // membuat graph
    createEmpty(&G);
    // membuat simpul awal dan akhir jalur
    simpul *begin;
    simpul *end;

    data source, dest;

    // penanda nilai awal node pertama
    int count = 0;
    do {
        scanf(" %c", &source.c);
        // nilai kunjungan tiap simpul
        source.visited = count == 0 ? 1 : 0;
        if(source.c != '0') {
            // jika masukan pertama bukan '0'
            scanf(" %c", &dest.c);
            dest.visited = 0;
            if(findSimpul(source, G) == NULL) {
                // jika simpul belum ada
                // tambahkan
                addSimpul(source, &G);
            }
            if(findSimpul(dest, G) == NULL) {
                // jika simpul belum ada
                // tambahkan
                addSimpul(dest, &G);
            }
            // cari awal dan akhir simpul untuk membuat jalur
            begin = findSimpul(source, G);
            end = findSimpul(dest, G);
            if((begin != NULL) && (end != NULL)) {
                addJalur(begin, end);
            }
        }
        count++;
        // diulang selama masukan pertama bukan '0'
    } while(source.c != '0');

    // mengecek simpul pada graph
    cekGraph(G, G.first);

    // mencetak output
    printGraph(G);
    return 0;
}