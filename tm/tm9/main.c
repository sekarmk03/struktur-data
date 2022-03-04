#include "header.h"

int main() {
    tree T;
    data dataStr;
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    makeTree(dataStr, &T);
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root);
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root);
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root);
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root->child);
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root->child);
    printf("Step 1:\n");
    printf("================\n");
    printTreePreOrder(T.root, T.root);
    printf("\n");
    delChild(T.root->child->child->sibling, T.root->child);
    printTreePreOrder(T.root, T.root);
    printf("\n");
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root->child->sibling);
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root->child->sibling);
    scanf("%s%d", dataStr.nama, &dataStr.nilai);
    addChild(dataStr, T.root->child->sibling->sibling);
    printTreePreOrder(T.root, T.root);
    printf("\n");
    printf("Step 2:\n");
    printf("================\n");
    tree T2;
    copyTree(T.root, &T2.root);
    if(isEqual(T.root, T2.root) == 1) {
        printf("Sama\n");
    } else {
        printf("Tidak Sama\n");
    }
    printf("Step 3:\n");
    printf("================\n");
    // char cari[100];
    // scanf("%s", cari);
    simpul *find1 = findSimpul("Gian", T.root->child->child);
    if(find1 != NULL) {
        printf("Gian ditemukan\n");
    } else {
        printf("Gian tidak ditemukan\n");
    }
    simpul *find2 = findSimpul("Gian", T.root->child->sibling);
    if(find2 != NULL) {
        printf("Gian ditemukan\n");
    } else {
        printf("Gian tidak ditemukan\n");
    }
    simpul *find3 = findSimpul("Gian", T.root);
    if(find3 != NULL) {
        printf("Gian ditemukan\n");
    } else {
        printf("Gian tidak ditemukan\n");
    }
    return 0;
}