#include "header.h"

void makeTree(data c, tree *T) {
    simpul *node;
    node = (simpul*)malloc(sizeof(simpul));
    strcpy(node->kontainer.nama, c.nama);
    node->kontainer.nilai = c.nilai;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(data c, simpul *root) {
    if(root != NULL) {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */
        simpul *baru;
        baru = (simpul*)malloc(sizeof(simpul));
        strcpy(baru->kontainer.nama, c.nama);
        baru->kontainer.nilai = c.nilai;
        baru->child = NULL;

        if(root->child == NULL) {
        /* jika simpul root belum memiliki simpul
        anak maka simpul baru menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        } else {
            if(root->child->sibling == NULL) {
            /* jika simpul root memiliki anak yang belum
            memiliki saudara, maka simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            } else {
                simpul *last = root->child;
                /* mencari simpul anak terakhir karena akan
                dikaitkan dengan simpul baru sebagai simpul
                anak terakhir yang baru, simpul anak terakhir
                adalah yang memiliki sibling simpul anak pertama,
                maka selama belum sampai pada simpul anak terakhir,
                penunjuk last akan berjalan ke simpul anak berikutnya */
                while(last->sibling != root->child) {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul **root) {
    if((*root) != NULL) {
        /* jika simpul root tidak kosong */
        if((*root)->child != NULL) {
            if((*root)->child->sibling == NULL) {
                /* jika hanya memiliki satu simpul anak */
                delAll(&(*root)->child);
            } else {
                simpul *bantu;
                simpul *proses;
                bantu = (*root)->child;
                while(bantu->sibling != (*root)->child){
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(&proses);
                }
                delAll(&bantu);
            }
            free((*root)->child);
            (*root)->child = NULL;
        }
        free(*root);
        *root = NULL;
    }
}

// void delChild(data c, simpul *root) {
    // if(root != NULL) {
    //     simpul *hapus = root->child;
    //     if(hapus != NULL) {
    //         if(hapus->sibling == NULL) {
    //         /*jika hanya mempunyai satu anak*/
    //             if((root->child->kontainer.nilai == c.nilai) && (strcmp(root->child->kontainer.nama, c.nama) == 0)) {
    //                 delAll(&root->child);
    //                 root->child = NULL;
    //             } else {
    //                 printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
    //             }
    //         } else {
    //         /*jika memiliki lebih dari satu simpul anak*/
    //             simpul *prev = NULL;
    //             /*mencari simpul yang akan dihapus*/
    //             int ketemu = 0;
    //             while((hapus->sibling != root->child) && (ketemu == 0)) {
    //                 if((hapus->kontainer.nilai == c.nilai) && (strcmp(hapus->kontainer.nama, c.nama) == 0)) {
    //                     ketemu = 1;
    //                 } else {
    //                     prev = hapus;
    //                     hapus = hapus->sibling;
    //                 }
    //             }
    //             /* memproses simpul anak terakhir karena
    //             belum terproses dalam pengulangan */
    //             if((ketemu == 0) && ((hapus->kontainer.nilai == c.nilai) && (strcmp(hapus->kontainer.nama, c.nama) == 0))) {
    //                 ketemu = 1;
    //             }
    //             if(ketemu == 1) {
    //                 simpul *last = root->child;
    //                 /* mencari simpul anak terakhir untuk
    //                 membantu proses atau pemeriksaan jika yang
    //                 dihapus nantinya anak terakhir */
    //                 while(last->sibling != root->child) {
    //                     last = last->sibling;
    //                 }
    //                 if(prev == NULL) {
    //                     /*jika simpul yang dihapus anak pertama*/
    //                     if((hapus->sibling == last) && (last->sibling == root->child)) {
    //                     /*jika hanya ada dua anak*/
    //                         root->child = last;
    //                         last->sibling = NULL;
    //                     } else {
    //                     /* jika memiliki simpul anak lebih dari dua simpul */
    //                         root->child = hapus->sibling;
    //                         last->sibling = root->child;
    //                     }
    //                 } else {
    //                     if((prev == root->child) && (last->sibling == root->child)) {
    //                     /* jika hanya ada dua simpulanak dan
    //                     yang dihapus adalah simpul anak kedua */
    //                         root->child->sibling = NULL;
    //                     } else {
    //                     /* jika yang dihapus bukan simpul anak
    //                     pertama dan simpul root memiliki simpul
    //                     anak lebih dari dua simpul */
    //                         prev->sibling = hapus->sibling;
    //                         hapus->sibling = NULL;
    //                     }
    //                 }
    //                 delAll(&hapus);
    //             } else {
    //                 printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
    //             }
    //         }
    //     }
    // }
// }

void delChild(simpul *del, simpul *root) {
    if(root != NULL) {
        simpul *hapus = root->child;
        if(hapus != NULL) {
            if(hapus->sibling == NULL) {
            /*jika hanya mempunyai satu anak*/
                if((root->child == del)) {
                    delAll(&root->child);
                    root->child = NULL;
                } else {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            } else {
            /*jika memiliki lebih dari satu simpul anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
                int ketemu = 0;
                while((hapus->sibling != root->child) && (ketemu == 0)) {
                    if(hapus == del) {
                        ketemu = 1;
                    } else {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                /* memproses simpul anak terakhir karena
                belum terproses dalam pengulangan */
                if((ketemu == 0) && (hapus == del)) {
                    ketemu = 1;
                }
                if(ketemu == 1) {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
                    membantu proses atau pemeriksaan jika yang
                    dihapus nantinya anak terakhir */
                    while(last->sibling != root->child) {
                        last = last->sibling;
                    }
                    if(prev == NULL) {
                        /*jika simpul yang dihapus anak pertama*/
                        if((hapus->sibling == last) && (last->sibling == root->child)) {
                        /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        } else {
                        /* jika memiliki simpul anak lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    } else {
                        if((prev == root->child) && (last->sibling == root->child)) {
                        /* jika hanya ada dua simpulanak dan
                        yang dihapus adalah simpul anak kedua */
                            root->child->sibling = NULL;
                        } else {
                        /* jika yang dihapus bukan simpul anak
                        pertama dan simpul root memiliki simpul
                        anak lebih dari dua simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(&hapus);
                } else {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}


simpul* findSimpul(char cari[], simpul *root) {
    simpul *hasil = NULL;
    if(root != NULL) {
        if((strcmp(root->kontainer.nama, cari) == 0)) {
            hasil = root;
        } else {
            simpul *bantu = root->child;
            if(bantu != NULL) {
                if(bantu->sibling == NULL) {
                /*jika memiliki satu simpul anak*/
                    if((strcmp(bantu->kontainer.nama, cari) == 0)) {
                        hasil = bantu;
                    } else {
                        hasil = findSimpul(cari, bantu);
                    }
                } else {
                /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while((bantu->sibling != root->child) && (ketemu == 0)) {
                        if((strcmp(bantu->kontainer.nama, cari) == 0)) {
                            hasil = bantu;
                            ketemu = 1;
                        } else {
                            hasil = findSimpul(cari, bantu);
                            bantu = bantu->sibling;
                            if(hasil != 0) {
                                ketemu = 1;
                            }
                        }
                    }
                    /*memproses simpul anak terakhir karena belum
                    terproses dalam pengulangan*/
                    if(ketemu == 0) {
                        if((strcmp(bantu->kontainer.nama, cari) == 0)) {
                            hasil = bantu;
                        } else {
                            hasil = findSimpul(cari, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void printTreePreOrder(simpul *root, simpul *almtRoot) {
    if(root != NULL) {
        // printf("%s %d * ", root->kontainer.nama, root->kontainer.nilai);
        if(root == almtRoot) {
            // jika simpul yg ditunjuk adalah root utama
            printf("%s %d", root->kontainer.nama, root->kontainer.nilai);
        } else {
            // jika simpul yg ditunjuk bukan root utama
            printf("-%s %d", root->kontainer.nama, root->kontainer.nilai);
        }
        simpul *bantu = root->child;
        if(bantu != NULL) {
            if(bantu->sibling == NULL) {
            /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu, almtRoot);
            } else {
            /*jika memiliki banyak simpul anak*/
            /*mencetak simpul anak*/
                while(bantu->sibling != root->child) {
                    printTreePreOrder(bantu, almtRoot);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum
                terproses dalam pengulangan*/
                printTreePreOrder(bantu, almtRoot);
            }
        }
    } else {
        printf("Kosong\n");
    }
}

void printTreePostOrder(simpul *root, simpul *almtRoot) {
    if(root != NULL) {
        simpul *bantu = root->child;
        if(bantu != NULL) {
            if(bantu->sibling == NULL) {
            /*jika memiliki satu simpul anak*/
                printTreePostOrder(bantu, almtRoot);
            } else {
            /*jika memiliki banyak simpul anak*/
            /*mencetak simpul anak*/
                while(bantu->sibling != root->child) {
                    printTreePostOrder(bantu, almtRoot);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena
                belum terproses dalam pengulangan*/
                printTreePostOrder(bantu, almtRoot);
            }
        }
        printf("%s %d", root->kontainer.nama, root->kontainer.nilai);
        if(root != almtRoot) {
            // jika bukan elemen root utama
            printf("-");
        }
    } else {
        printf("Kosong\n");
    }
}

void copyTree(simpul *root1, simpul **root2){
    if(root1 != NULL) {
        (*root2) = (simpul*)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        (*root2)->sibling = NULL;
        (*root2)->child = NULL;
        if(root1->child != NULL) {
            if(root1->child->sibling == NULL) {
            /*jika memiliki satu simpul anak*/
                copyTree(root1->child, &(*root2)->child);
            } else {
            /*jika memiliki banyak simpul anak*/
                simpul *bantu1 = root1->child;
                simpul *bantu2 = (*root2)->child;
                while(bantu1->sibling != root1->child) {
                    copyTree(bantu1, &bantu2);
                    bantu1 = bantu1->sibling;
                    bantu2 = bantu2->sibling;
                }
                /*memproses simpul anak terakhir karena
                belum terproses dalam pengulangan*/
                copyTree(bantu1, &bantu2);
            }
        }
    }
}

int isEqual(simpul *root1, simpul *root2) {
    int hasil = 1;
    if((root1 != NULL) && (root2 != NULL)) {
        if((root1->kontainer.nilai != root2->kontainer.nilai) || (strcmp(root1->kontainer.nama, root2->kontainer.nama) != 0)) {
            hasil = 0;
        } else {
            if((root1->child != NULL) && (root2->child != NULL)) {
                if(root1->child->sibling == NULL) {
                    /*jika memiliki satu simpul anak*/
                    hasil = isEqual(root1->child, root2->child);
                } else {
                    /*jika memiliki banyak simpul anak*/
                    simpul *bantu1 = root1->child;
                    simpul *bantu2 = root2->child;
                    while(bantu1->sibling != root1->child) {
                        if((bantu1 != NULL) && (bantu2 != NULL)) {
                            hasil = isEqual(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        } else {
                            hasil = 0;
                            break;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                    hasil = isEqual(bantu1, bantu2);
                }
            }
        }
    } else {
        if((root1 != NULL) || (root2 != NULL)) {
            hasil = 0;
        }
    }
    return hasil;
}