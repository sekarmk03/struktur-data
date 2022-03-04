#include "header.h"

/* Membuat Tree Baru */
void makeTree(char c, tree *T) {
    simpul *baru;
    baru = (simpul*)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

/* Menambah Simpul di Kanan Simpul yg Ditunjuk */
void addRight(char c, simpul *root) {
    if(root->right == NULL) {
        simpul *baru;
        baru = (simpul*)malloc(sizeof(simpul)); // meminta memori
        baru->kontainer = c; // memasukkan isi simpul
        baru->right = NULL; // simpul kanan dikosongkan
        baru->left = NULL; // simpul kiri dikosongkan
        root->right = baru; // simpul baru dimasukkan ke simpul yg ditunjuk (root)
    } else {
        printf("sub pohon kanan telah terisi");
    }
}

/* Menambah Simpul di Kiri Simpul yg Ditunjuk */
// alur sama seperti prosedur addRight() hanya berbeda di posisi simpul
void addLeft(char c, simpul *root) {
    if(root->left == NULL) {
        simpul *baru;
        baru = (simpul*)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    } else {
        printf("sub pohon kiri telah terisi");
    }
}

/* Menghapus Seluruh Simpul Tree */
void delAll(simpul *root) {
    if(root != NULL) {
        // dipanggil rekursif
        // dihapus dari paling kiri bawah
        delAll(root->left);
        delAll(root->right);
        free(root); // membebaskan memori root
    }
}

/* Menghapus Simpul di Kanan */
void delRight(simpul *root) {
    if(root != NULL) {
        // jika root (simpul yg ditunjuk) tidak kosong
        if(root->right != NULL) {
            // jika ada simpul kanannya
            delAll(root->right); // hapus bersama childnya
            root->right = NULL;
        }
    }
}

/* Menghapus Simpul di Kiri */
// sama seperti prosedur delRight() hanya berbeda di posisi simpul
void delLeft(simpul *root) {
    if(root != NULL) {
        if(root->left != NULL) {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

/* Mencetak Isi Simpul dari Atas Kiri ke Bawah */
void printTreePreOrder(simpul *root, simpul *almtRoot) {
    if(root != NULL) {
        // jika simpul yg ditunjuk (root) tidak kosong
        if(root == almtRoot) {
            // jika simpul yg ditunjuk adalah root utama
            printf("%c", root->kontainer);
        } else {
            // jika simpul yg ditunjuk bukan root utama
            printf(" - %c", root->kontainer);
        }
        // rekursif, kiri dulu
        printTreePreOrder(root->left, almtRoot);
        // baru kanan kalau kiri NULL
        printTreePreOrder(root->right, almtRoot);
    }
}

/* Mencetak Isi Simpul Kiri lalu Kanan */
void printTreeInOrder(simpul *root) {
    if(root != NULL) {
        // rekursif, kiri dulu
        printTreeInOrder(root->left);
        if(root->left != NULL) {
            // jika kirinya ada
            printf(" - ");
        }
        printf("%c", root->kontainer);
        if(root->right != NULL) {
            // jika kanannya ada
            printf(" - ");
        }
        // rekursif, simpul yg kanan
        printTreeInOrder(root->right);
    }
}

/* Mencetak Isi Simpul dari Kanan Bawah ke Kiri */
void printTreePostOrder(simpul *root, simpul *almtRoot) {
    if(root != NULL) {
        // rekursif, kiri dulu
        printTreePostOrder(root->left, almtRoot);
        // kalau kiri NULL, pindah ke kanan
        printTreePostOrder(root->right, almtRoot);
        printf("%c", root->kontainer);
        if(root != almtRoot) {
            // jika bukan elemen root utama
            printf(" - ");
        }
    }
}

void copyTree(simpul *root1, simpul **root2) {
    if(root1 != NULL) {
        (*root2) = (simpul*)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        printf("root : %c\n", root1->kontainer);
        if(root1->left != NULL) {
            printf("< %c\n", root1->left->kontainer);
            copyTree(root1->left, &(*root2)->left);
        }
        if(root1->right != NULL) {
            printf("> %c\n", root1->right->kontainer);
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

int isEqual(simpul *root1, simpul *root2) {
    int hasil = 1;
    if((root1 != NULL) && (root2 != NULL)) {
        if(root1->kontainer != root2->kontainer) {
            hasil = 0;
        } else {
            hasil = isEqual(root1->left, root2->left);
            hasil = isEqual(root1->right, root2->right);
        }
    } else {
        if((root1 != NULL) || (root2 != NULL)) {
            hasil = 0;
        }
    }
    return hasil;
}