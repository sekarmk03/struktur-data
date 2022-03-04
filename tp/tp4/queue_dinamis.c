#include "header.h"

int main() {
    dtPengantri pengantri; // data inputan
    char jnsMember[20]; // membantu encoding
    queue Q1; // queue
    createEmpty(&Q1); // membuat queue kosong
    do {
        scanf("%s", pengantri.nama);
        if(strcmp(pengantri.nama, "stop") != 0) {
            // jika nama bukan stop maka lanjut ke masukan berikutnya
            scanf("%s%d", jnsMember, &pengantri.waktu);
            if(strcmp(jnsMember, "platinum") == 0) {
                // jika platinum, priority = 1
                pengantri.priority = 1;
            } else if(strcmp(jnsMember, "gold") == 0) {
                // jika gold, priority = 2
                pengantri.priority = 2;
            } else if(strcmp(jnsMember, "silver") == 0) {
                // jika silver, priority = 3
                pengantri.priority = 3;
            } else {
                // jika nonmember, priority = 4
                pengantri.priority = 4;
            }
            // menambah elemen
            addPriority(pengantri, &Q1);
        }
        // diulang selama nama bukan stop
    } while(strcmp(pengantri.nama, "stop") != 0);
    // mencetak elemen queue sisa
    printQueue(Q1);
    return 0;
}