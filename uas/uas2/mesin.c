#include "header.h"

/* Prosedur Membuat Graph */
void createEmpty(graph *G) {
    (*G).first = NULL;
}

/* Prosedur Menambahkan Graph */
void addSimpul(data c, graph *G) {
    simpul *baru;
    // meminta memori
    baru = (simpul*)malloc(sizeof(simpul));
    // mengisi data
    baru->kontainer = c;
    baru->next = NULL;
    baru->arc = NULL;
    if((*G).first == NULL) {
        // jika graph masih kosong
        (*G).first = baru;
    } else {
        // jika graph sudah ada isinya
        simpul *last = (*G).first;
        while(last->next != NULL) {
            last = last->next;
        }
        // simpan diakhir
        last->next = baru;
    }
}

/* Proseur Membuat Jalur */
void addJalur(simpul *awal, simpul *tujuan) {
    jalur *baru;
    // meminta memori
    baru = (jalur*)malloc(sizeof(jalur));
    baru->next_jalur = NULL;
    baru->dest = tujuan;
    if(awal->arc == NULL) {
        // menambah jalur pertama
        awal->arc = baru;
    } else {
        // menmabah jalur terakhir jika jalur sudah ada
        jalur *last = awal->arc;
        while (last->next_jalur != NULL) {
            last = last->next_jalur;
        }
        last->next_jalur = baru;
    }   
}

/* Prosedur Mencari Posisi Simpul pada Graph */
simpul* findSimpul(data c, graph G) {
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    int ketemu = 0;
    while((bantu != NULL) && (ketemu == 0)) {
        // jika belum mencapai simpul terakhir dan data yang dicari belum ketemu
        if(bantu->kontainer.c == c.c) {
            // jika data ketemu
            hasil = bantu;
            ketemu = 1;
        } else {
            // jika belum ketemu
            bantu = bantu->next;
        }
    }
    return hasil;
}

void delJalur(char ctujuan, simpul *awal) {
    jalur *hapus = awal->arc;
    if(hapus != NULL){
        jalur *prev = NULL;
        int ketemu = 0;
        while((hapus != NULL) && (ketemu == 0)) {
            if(hapus->dest->kontainer.c == ctujuan) {
                ketemu = 1;
            } else {
                prev = hapus;
                hapus = hapus->next_jalur;
            }
        }
        if(ketemu == 1) {
            if(prev == NULL) {
                awal->arc = hapus->next_jalur;
                hapus->next_jalur = NULL;
            } else {
                if(hapus->next_jalur == NULL) {
                    prev->next_jalur = NULL;
                } else {
                    prev->next_jalur = hapus->next_jalur;
                    hapus->next_jalur = NULL;
                }
            }
            free(hapus);
        }
    }
}

void delAllJalur(simpul *awal) {
    jalur *bantu;
    bantu = awal->arc;
    jalur *hapus;
    while(bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next_jalur;
        awal->arc = bantu;
        hapus->next_jalur = NULL;
        free(hapus);
    }
}

/* Prosedur Menghapus Simpul */
void delSimpul(data c, graph *G) {
    simpul *hapus = (*G).first;
    if(hapus != NULL) {
        simpul *prev = NULL;
        int ketemu = 0;
        while((hapus != NULL) && (ketemu == 0)) {
            if(hapus->kontainer.c == c.c) {
                ketemu = 1;
            } else {
                prev = hapus;
                hapus = hapus->next;
            }
        }
        if(ketemu == 1) {
            simpul *bantu;
            bantu = (*G).first;
            while(bantu != NULL) {
                if(bantu != hapus) {
                    delJalur(hapus->kontainer.c, bantu);
                }
                bantu = bantu->next;
            }
            delAllJalur(hapus);
            if(prev == NULL) {
                (*G).first = hapus->next;
                hapus->next = NULL;
            } else {
                if(hapus->next == NULL) {
                    prev->next = NULL;
                } else {
                    prev->next = hapus->next;
                    hapus->next = NULL;
                }
            }
            free(hapus);
        }
    }
}

/* Prosedur Mencetak Keluaran */
void printGraph(graph G) {
    simpul *bantu = G.first;
    int ada = 0; // penanda adanya cycle
    if(bantu != NULL) {
        while(bantu != NULL) {
            // menelusuri simpul
            // printf("Node %c\n", bantu->kontainer);
            jalur *bantu_arc = bantu->arc;
            while(bantu_arc != NULL){
                // printf("Jalur %c ke %c\n", bantu->kontainer.c,  bantu_arc->dest->kontainer.c);
                // printf("visited : %d\n", bantu->kontainer.visited);
                // menelusuri jalur
                if(bantu->kontainer.visited > 1) {
                    // jika dikunjungi
                    ada = 1;
                }
                bantu_arc = bantu_arc->next_jalur;
            }
            bantu = bantu->next;
        }
    } else {
        printf("Graph Kosong\n");
    }
    if(ada == 1) {
        printf("ada jalur memutar\n");
    } else {
        printf("tidak ada jalur memutar\n");
    }
}

// void cekGraph(graph G) {
//     simpul *bantu = G.first;
//     if(bantu != NULL) {
//         while(bantu != NULL) {
//             // printf("Node %c\n", bantu->kontainer);
//             bantu->kontainer.visited++;
//             jalur *bantu_arc = bantu->arc;
//             while(bantu_arc != NULL){
//                 printf("Jalur %c ke %c\n", bantu->kontainer.c,  bantu_arc->dest->kontainer.c);
//                 simpul *search = findSimpul(bantu_arc->dest->kontainer, G);

//                 printf("visited : %d\n", bantu->kontainer.visited);
//                 bantu_arc = bantu_arc->next_jalur;
//             }
//             bantu = bantu->next;
//         }
//     } else {
//         printf("Graph Kosong\n");
//     }
// }

// void cekGraph(graph G) {
//     simpul *bantu = G.first;
//     if(bantu != NULL) {
//         while(bantu != NULL) {
//             printf("Node %c\n", bantu->kontainer);
//             bantu->kontainer.visited++;
//             jalur *bantu_arc = bantu->arc;
//             while(bantu_arc != NULL){
//                 printf("Jalur %c ke %c\n", bantu->kontainer.c,  bantu_arc->dest->kontainer.c);
//                 simpul *search = findSimpul(bantu_arc->dest->kontainer, G);
//                 if(search->next != NULL) {
                    
//                 }

//                 bantu_arc = bantu_arc->next_jalur;
//             }
//             bantu = bantu->next;
//         }
//     } else {
//         printf("Graph Kosong\n");
//     }
// }

/* Percobaan Membuat Prosedur Pengecekan Simpul yang Sudah Dikunjungi */
void cekGraph(graph G, simpul *node) {
    if(node != NULL) {
        if(node != NULL) {
            // printf("Node %c\n", node->kontainer);
            // bantu->kontainer.visited++;
            jalur *bantu_arc = node->arc;
            while(bantu_arc != NULL){
                // printf("Jalur %c ke %c\n", node->kontainer.c,  bantu_arc->dest->kontainer.c);
                simpul *search = findSimpul(bantu_arc->dest->kontainer, G);
                if(search->next != NULL) {
                    search->kontainer.visited++;
                    cekGraph(G, search);
                }
                bantu_arc = bantu_arc->next_jalur;
            }
            node = node->next;
        }
    } else {
        return;
    }
}