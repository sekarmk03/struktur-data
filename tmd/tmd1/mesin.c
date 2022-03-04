#include "header.h"

/* Prosedur Membuat Tree */
void makeTree(data d, tree *T) {
    // membuat node
    simpul *node;
    node = (simpul*)malloc(sizeof(simpul));
    // mengisi data
    node->daerah = d;
    // membuat pointer anak dan saudara
    node->sibling = NULL;
    node->child = NULL;
    // memasang node ke root
    (*T).root = node;
}

/* Prosedur Menambah Child */
void addChild(data d, simpul *root) {
    if(root != NULL) {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */
        simpul *baru;
        baru = (simpul*)malloc(sizeof(simpul));
        baru->daerah = d;
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
                if(baru->daerah.korban > root->child->daerah.korban) {
                    root->child = baru;
                }
            } else {
                simpul *bantu = root->child;
                int stop = 0;
                if(baru->daerah.korban > bantu->daerah.korban) {
                    baru->sibling = root->child;
                    simpul *last = root->child;
                    while(last->sibling != root->child) {
                        last = last->sibling;
                    }
                    last->sibling = baru;
                    root->child = baru;
                    stop = 2;
                } else {
                    while(bantu->sibling != root->child && stop == 0) {
                        if(bantu->sibling->daerah.korban < baru->daerah.korban) {
                            baru->sibling = bantu->sibling;
                            bantu->sibling = baru;
                            stop = 1;
                        }
                        bantu = bantu->sibling;
                    }
                    /* mencari simpul anak terakhir karena akan
                    dikaitkan dengan simpul baru sebagai simpul
                    anak terakhir yang baru, simpul anak terakhir
                    adalah yang memiliki sibling simpul anak pertama,
                    maka selama belum sampai pada simpul anak terakhir,
                    penunjuk last akan berjalan ke simpul anak berikutnya */
                    if(stop == 0) {
                        if(baru->daerah.korban <= bantu->daerah.korban) {
                            baru->sibling = root->child;
                            bantu->sibling = baru;
                        }
                    }
                }
            }
        }
    }
}

/* Prosedur Menghapus Seluruh Anak */
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

/* Prosedur Menghapus Anak */
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
                        if((prev == root->child) && (last == hapus)) {
                        /* jika hanya ada dua simpul anak dan
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

/* Prosedur Mencari Node */
simpul* findSimpul(char cari[], simpul *root) {
    simpul *hasil = NULL;
    if(root != NULL) {
        if((strcmp(root->daerah.nama, cari) == 0)) {
            hasil = root;
        } else {
            simpul *bantu = root->child;
            if(bantu != NULL) {
                if(bantu->sibling == NULL) {
                    /*jika memiliki satu simpul anak*/
                    if((strcmp(bantu->daerah.nama, cari) == 0)) {
                        hasil = bantu;
                    } else {
                        hasil = findSimpul(cari, bantu);
                    }
                } else {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while((bantu->sibling != root->child) && (ketemu == 0)) {
                        if((strcmp(bantu->daerah.nama, cari) == 0)) {
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
                        if((strcmp(bantu->daerah.nama, cari) == 0)) {
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

/* Prosedur Mencetak Node */
void printTreePreOrder(simpul *root, int n, int len[]) {
    if(root != NULL) {
        // mencetak -> sesuai level
        printf("\n");
        if(n > 0) {
            for (int i = 0; i < len[n - 1]; i++)
            {
                printf(" ");
            }
        }
        root->daerah.level = n;
        printf("|%s - %d\n", root->daerah.nama, root->daerah.korban);
        simpul *bantu = root->child;
        if(bantu != NULL) {
            if(bantu->sibling == NULL) {
                /* jika memiliki satu simpul anak */
                printTreePreOrder(bantu, ++n, len);
                --n;
            } else {
                /* jika memiliki banyak simpul anak */
                /* mencetak simpul anak */
                while(bantu->sibling != root->child) {
                    printTreePreOrder(bantu, ++n, len);
                    --n;
                    bantu = bantu->sibling;
                }
                /* memproses simpul anak terakhir karena belum
                terproses dalam pengulangan */
                printTreePreOrder(bantu, ++n, len);
                --n;
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
        printf("%s %d\n", root->daerah.nama, root->daerah.korban);
    } else {
        printf("Kosong\n");
    }
}

int hitungKorban(simpul *root, simpul *almtRoot) {
    if(root != NULL) {
        int jumlah = 0;
        simpul *bantu = root->child;
        if(bantu != NULL) {
            if(bantu->sibling == NULL) {
            /*jika memiliki satu simpul anak*/
                jumlah += hitungKorban(bantu, almtRoot);
            } else {
            /*jika memiliki banyak simpul anak*/
            /*mencetak simpul anak*/
                while(bantu->sibling != root->child) {
                    jumlah += hitungKorban(bantu, almtRoot);
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena
                belum terproses dalam pengulangan*/
                jumlah += hitungKorban(bantu, almtRoot);
            }
            root->daerah.korban = jumlah;
        }
        // printf(">> %d\n", jumlah);
        // printf("%s %d\n", root->daerah.nama, root->daerah.korban);
        return root->daerah.korban;
    } else {
        printf("Kosong\n");
    }
}

void copyTree(simpul *root1, simpul **root2){
    if(root1 != NULL) {
        (*root2) = (simpul*)malloc(sizeof(simpul));
        (*root2)->daerah = root1->daerah;
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
        if((strcmp(root1->daerah.nama, root2->daerah.nama) != 0)) {
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

void explode(char str[], char first[], char second[], int *num, char splitter) {
    int tag = 0, f = 0, s = 0, v = 0;
    char temp[50];
    for (int i = 0; i < strlen(str); i++) {
        if(str[i] == splitter) {
            tag++;
            continue;
        }
        if(tag == 0) {
            first[f] = str[i];
            f++;
        }
        if(tag == 1) {
            second[s] = str[i];
            s++;
        }
        if(tag == 2) {
            temp[v] = str[i];
            v++;
        }
    }
    first[f] = '\0';
    second[s] = '\0';
    temp[v] = '\0';
    *num = 0;
    int digit = strlen(temp) - 1;
    for (int i = 0; i < strlen(temp); i++) {
        *num += ((temp[i] - 48) * (pow(10, digit)));
        digit--;
    }
}

void maxLenName(simpul *root, int n, int len[]) {
    if(root != NULL) {
        int curLen = strlen(root->daerah.nama) + totalDigit(root->daerah.korban) + 4;
        if(len[n] < curLen) {
            len[n] = curLen;
        }
        simpul *bantu = root->child;
        if(bantu != NULL) {
            if(bantu->sibling == NULL) {
                /* jika memiliki satu simpul anak */
                maxLenName(bantu, ++n, len);
                --n;
            } else {
                /* jika memiliki banyak simpul anak */
                /* mencetak simpul anak */
                while(bantu->sibling != root->child) {
                    maxLenName(bantu, ++n, len);
                    --n;
                    bantu = bantu->sibling;
                }
                /* memproses simpul anak terakhir karena belum
                terproses dalam pengulangan */
                maxLenName(bantu, ++n, len);
                --n;
            }
        }
    } else {
        printf("Kosong\n");
    }
}

int totalDigit(int num) {
    int digit = 0;
    while(num != 0) {
        num /= 10;
        digit++;
    }
    return digit;
}