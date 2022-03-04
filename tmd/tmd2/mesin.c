#include "header.h"

/* Prosedur Membuat Tree */
void makeTree(data d, tree *T) {
    // membuat node, meminta alokasi memori seukuran simpul
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
        // jika simpul root tidak kosong,
        // berarti dapat ditambahkan simpul anak
        simpul *baru;
        // membuat node, meminta alokasi memori seukuran simpul
        baru = (simpul*)malloc(sizeof(simpul));
        // mengisikan data
        baru->daerah = d;
        baru->child = NULL;
        if(root->child == NULL) {
            // jika simpul root belum memiliki simpul
            // anak maka simpul baru menjadi anak pertama
            baru->sibling = NULL;
            root->child = baru;
        } else {
            if(root->child->sibling == NULL) {
                // jika root baru memiliki satu anak
                baru->sibling = root->child;
                root->child->sibling = baru;
                if(baru->daerah.korban > root->child->daerah.korban) {
                    // jika simpul baru memiliki jumlah korban > simpul anak pertama
                    // maka simpul baru akan menjadi anak pertama
                    root->child = baru;
                }
            } else {
                // jika root sudah memiliki anak lebih dari satu
                simpul *bantu = root->child;
                int stop = 0; // penanda child baru sudah menemukan tempat yg pas
                if(baru->daerah.korban > bantu->daerah.korban) {
                    // jika jumlah korban simpul baru > jumlah korban anak pertama
                    // maka simpul baru akan menjadi anak perta,a
                    baru->sibling = root->child;
                    simpul *last = root->child;
                    // mencari anak terakhir pada root
                    while(last->sibling != root->child) {
                        last = last->sibling;
                    }
                    // anak terakhir dihubungkan ke anak pertama yang baru
                    last->sibling = baru;
                    root->child = baru;
                    stop = 2; // tandai
                } else {
                    // jika jumlah korban simpul baru <= jumlah korban anak pertama
                    // dilakukan penelusuran thd seluruh anak pada root
                    while(bantu->sibling != root->child && stop == 0) {
                        // selama saudara simpul saat ini bukan anak terakhir
                        // dan simpul baru belum menemukan tempat
                        if(bantu->sibling->daerah.korban < baru->daerah.korban) {
                            // jika korban saudara simpul saat ini < korban simpul baru
                            // maka simpul baru ditempatkan tepat setelah simpul saat ini
                            baru->sibling = bantu->sibling;
                            bantu->sibling = baru;
                            stop = 1; // tandai
                        }
                        // iterasi penelusuran simpul
                        bantu = bantu->sibling;
                    }
                    // mengecek simpul anak terakhir jika penanda stop masih nol
                    // (jika simpul baru belum menemukan tempat yg pas)
                    if(stop == 0) {
                        if(baru->daerah.korban <= bantu->daerah.korban) {
                            // jika korban simpul baru <= korban simpul terakhir
                            // maka simpul baru akan menjadi simpul terakhir
                            baru->sibling = root->child;
                            bantu->sibling = baru;
                        }
                    }
                }
            }
        }
    }
}

/* Prosedur Mencari Node */
simpul* findSimpul(char cari[], simpul *root) {
    simpul *hasil = NULL;
    if(root != NULL) {
        // jika tree tidak kosong
        if((strcmp(root->daerah.nama, cari) == 0)) {
            // jika simpul yg dicari adalah root
            hasil = root;
        } else {
            // jika simpul yg dicari bukan root (anak2nya)
            simpul *bantu = root->child;
            if(bantu != NULL) {
                // jika root memiliki anak
                if(bantu->sibling == NULL) {
                    // jika memiliki satu simpul anak
                    if((strcmp(bantu->daerah.nama, cari) == 0)) {
                        // jika anaknya adalah simpul yg dicari
                        hasil = bantu;
                    } else {
                        // jika anaknya bukan simpul yg dicari
                        // rekursif, telusuri level root di bawahnya
                        hasil = findSimpul(cari, bantu);
                    }
                } else {
                    // jika memiliki banyak simpul anak
                    int ketemu = 0;
                    while((bantu->sibling != root->child) && (ketemu == 0)) {
                        // selama saudara simpul saat ini bukan simpul terakhir
                        // dan simpul yg dicari belum ketemu
                        if((strcmp(bantu->daerah.nama, cari) == 0)) {
                            // jika ketemu di saudaranya
                            hasil = bantu;
                            ketemu = 1; // tandai
                        } else {
                            // jika tidak ketemu, rekursif
                            // telusuri ke level root di bawahnya
                            hasil = findSimpul(cari, bantu);
                            if(hasil != 0) {
                                // jika ditemukan dalam rekursif
                                ketemu = 1; // tandai
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    // memproses simpul anak terakhir
                    if(ketemu == 0) {
                        // jika simpul yg dicari belum ketemu
                        if((strcmp(bantu->daerah.nama, cari) == 0)) {
                            // jika ketemu di anak terakhir
                            hasil = bantu;
                        } else {
                            // jika belum ketemu di anak terakhir
                            // telurusi level di bawah anak terakhir
                            hasil = findSimpul(cari, bantu);
                        }
                    }
                }
            }
        }
    }
    // kembalikan alamat simpul hasil pencarian
    return hasil;
}

/* Prosedur Mencetak Node */
void printTreePreOrder(simpul *root, int n, int len[]) {
    // parameter n menandakan level kedalaman tree
    // parameter len menandakan jumlah spasi yg harus dicetak
    if(root != NULL) {
        // mencetak spasi sesuai level tree dan panjang nama daerah terpanjang
        printf("\n");
        if(n > 0) {
            // spasi di cetak jika bukan mencetak root paling atas
            // atau jika level kedalaman tree > 0
            for (int i = 0; i < len[n - 1]; i++) {
                // cetak spasi sebanyak nilai pada array panjang string
                printf(" ");
            }
        }
        // mencetak nama daerah dan jumlah korban (simpul tree)
        printf("|%s - %d\n", root->daerah.nama, root->daerah.korban);

        // persiapan mencetak simpul berikutnya (anak dari root)
        simpul *bantu = root->child;
        if(bantu != NULL) {
            // jika root memiliki simpul anak
            if(bantu->sibling == NULL) {
                // jika root memiliki satu simpul anak
                printTreePreOrder(bantu, ++n, len);
                --n;
            } else {
                // jika root memiliki banyak simpul anak
                while(bantu->sibling != root->child) {
                    // simpul anak ditelurusi satu per satu sampai anak terakhir
                    // dengan memanggil rekursif untuk penelusuran level di bawahnya
                    printTreePreOrder(bantu, ++n, len);
                    --n;
                    // iterasi pengecekan simpul selanjutnya
                    bantu = bantu->sibling;
                }
                // memproses simpul anak terakhir
                printTreePreOrder(bantu, ++n, len);
                --n;
            }
        }
    } else {
        printf("Kosong\n");
    }
}

/* Fungsi Menghitung Jumlah Korban Setiap Daerah (Simpul) */
int hitungKorban(simpul *root) {
    if(root != NULL) {
        // jika root tidak kosong
        int jumlah = 0;
        simpul *bantu = root->child;
        if(bantu != NULL) {
            // jika root memiliki anak
            if(bantu->sibling == NULL) {
                // jika memiliki satu simpul anak
                jumlah += hitungKorban(bantu);
            } else {
                // jika memiliki banyak simpul anak
                // simpul anak ditelusuri satu per satu
                while(bantu->sibling != root->child) {
                    // selama saudara simpul saat ini bukan simpul terakhir
                    // telusuri level di bawahnya untuk mendapatkan jumlah
                    // korban dari simpul di bawahnya
                    jumlah += hitungKorban(bantu);
                    bantu = bantu->sibling; // lanjut ke saudara berikutnya
                }
                // memproses simpul anak terakhir untuk dicari jumlah korbannya
                jumlah += hitungKorban(bantu);
            }
            // mengisikan korban root saat ini dengan total jumlah
            // yg hasil penjumlahan korban simpul di bawahnya
            root->daerah.korban = jumlah;
        }
        // mengembalikan nilai jumlah korban pada root
        return root->daerah.korban;
    } else {
        printf("Kosong\n");
    }
}

/* Prosedur Memecah String */
void explode(char str[], char first[], char second[], int *num, char splitter) {
    // parameter splitter untuk menandai karakter pemisah string
    // dari 1 string dipecah menjadi 2 string dan 1 integer
    int tag = 0, f = 0, s = 0, v = 0;
    char temp[50];
    for (int i = 0; i < strlen(str); i++) {
        // diulang sepanjang string
        if(str[i] == splitter) {
            // jika bertemu karakter pemisah, tandai dan
            // lanjutkan iterasi tanpa mengeksekusi kode berikutnya
            tag++;
            continue;
        }
        if(tag == 0) {
            // jika tag 0, isi ke string pertama
            first[f] = str[i];
            f++;
        }
        if(tag == 1) {
            // jika tag 1, isi ke string kedua
            second[s] = str[i];
            s++;
        }
        if(tag == 2) {
            // jika tag 2, isi ke string temp
            // untuk diubah ke integer nantinya
            temp[v] = str[i];
            v++;
        }
    }
    // menutup semua string
    first[f] = '\0';
    second[s] = '\0';
    temp[v] = '\0';
    *num = 0;
    // mengubah string ke integer
    int digit = strlen(temp) - 1;
    for (int i = 0; i < strlen(temp); i++) {
        // selama panjang string, ubah nilai ascii
        // kalikan dengan 10 pangkat jumlah digit
        // tambahkan setiap hasil perkalian
        *num += ((temp[i] - 48) * (pow(10, digit)));
        digit--;
    }
}

/* Prosedur Mencari Nama Daerah Terpanjang Setiap Level */
void maxLenName(simpul *root, int level, int len[]) {
    if(root != NULL) {
        // jika root tidak kosong
        // simpan panjang nama daerah saat ini ditambah jumlah digit korban
        int curLen = strlen(root->daerah.nama) + totalDigit(root->daerah.korban) + 4;
        if(len[level] < curLen) {
            // jika panjang yg tersimpan di len[level] < panjang saat ini
            // simpan panjang saat ini ke array len[level]
            len[level] = curLen;
        }
        simpul *bantu = root->child;
        if(bantu != NULL) {
            // jika root memiliki simpul anak
            if(bantu->sibling == NULL) {
                // jika memiliki satu simpul anak
                // telusuri simpul anak
                maxLenName(bantu, ++level, len);
                --level;
            } else {
                // jika memiliki banyak simpul anak
                // telusuri semua simpul anak
                while(bantu->sibling != root->child) {
                    // selama saudara simpul saat ini bukan simpul terakhir
                    // telusuri simpul anak (simpul di bawahnya)
                    maxLenName(bantu, ++level, len);
                    --level;
                    bantu = bantu->sibling; // iterasi
                }
                // memproses simpul anak terakhir
                maxLenName(bantu, ++level, len);
                --level;
            }
        }
    } else {
        printf("Kosong\n");
    }
}

/* Fungsi Menghitung Total Digit */
int totalDigit(int num) {
    int digit = 0;
    while(num != 0) {
        // selama nilai num belum nol
        num /= 10;
        digit++;
    }
    // mengembalikan nilai var digit
    return digit;
}