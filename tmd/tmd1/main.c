#include "header.h"

int main() {
    tree T;
    data tParent, tChild;
    int maxLen[50] = {0};
    // jumlah = 0;
    char str[250];
    int n = 0;
    simpul *nodeRoot;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        explode(str, tParent.nama, tChild.nama, &tChild.korban, '#');
        if(strcmp(tParent.nama, "null") == 0) {
            makeTree(tChild, &T);
        } else {
            nodeRoot = findSimpul(tParent.nama, T.root);
            addChild(tChild, nodeRoot);
        }
    }
    hitungKorban(T.root, T.root);
    // printTreePostOrder(T.root, T.root);
    maxLenName(T.root, 0, maxLen);
    int i = 1;
    while(maxLen[i+1] != 0) {
        maxLen[i] += maxLen[i - 1];
        i++; // jumlah level
    }
    maxLen[i] = 0;
    // for (int j = 0; j < i; j++) {
    //     printf("%d\n", maxLen[j]);
    // }
    printf("pohon lengkap:\n");
    printTreePreOrder(T.root, 0, maxLen);
    int m = 0;
    scanf("%d", &m);
    printf("\nSub-pohon:\n");
    for (int j = 0; j < m; j++) {
        char subTree[100];
        scanf("%s", subTree);
        nodeRoot = findSimpul(subTree, T.root);
        for (int k = 0; k <= i; k++) {
            maxLen[k] = 0;
        }
        maxLenName(nodeRoot, 0, maxLen);
        i = 1;
        while(maxLen[i+1] != 0) {
            maxLen[i] += maxLen[i - 1];
            i++; // jumlah level
        }
        maxLen[i] = 0;
        printTreePreOrder(nodeRoot, 0, maxLen);
    }
    
    // tree T2;
    // copyTree(T.root, &T2.root);
    // printTreePreOrder(T2.root, 0, 1);
    
    return 0;
}