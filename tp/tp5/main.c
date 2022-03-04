#include "header.h"

int main() {
    tree T;
    char query1[30];
    int count = 1, prt = 0;
    do {
        scanf("%s", query1);
        if(strcmp(query1, "DONE;") != 0) {
            // jika query pertama bukan DONE;
            char query2[100], query3[100];
            simpul *nodeRoot;
            if(strcmp(query1, "MAKETREE") == 0) {
                // jika query pertama adalah MAKETREE
                int i = 0;
                do {
                    // masukkan query kedua (akar)
                    scanf(" %c", &query2[i]);
                    i++;
                } while(query2[i-1] != ';');
                query2[i-1] = '\0';
                // buat tree
                makeTree(query2, &T);
            } else if(strcmp(query1, "CHILD") == 0 || strcmp(query1, "DELLCHILD") == 0) {
                // jika query pertama CHILD atau DELLCHILD
                // masukkan query kedua (anak)
                scanf("%s", query2);
                int i = 0;
                do {
                    // masukkan query ketiga (orang tua)
                    scanf(" %c", &query3[i]);
                    i++;
                } while(query3[i-1] != ';');
                query3[i-1] = '\0';
                // cari node orang tua
                nodeRoot = count == 1 ? T.root : findSimpul(query3, T.root);
                if(strcmp(query1, "DELLCHILD") == 0) {
                    // jika query kedua DELLCHILD
                    // cari node anak yg mau dihapus
                    simpul *delRoot = findSimpul(query2, T.root);
                    // hapus anak
                    delChild(delRoot, nodeRoot);
                } else {
                    // jika query kedua CHILD
                    // tambahkan anak
                    addChild(query2, nodeRoot);
                }
            } else if(strcmp(query1, "PREORDER;") == 0) {
                // jika query pertama PREORDER;
                // cetak node tree
                // param1 : orang tua
                // param 2 : mencetak -> berdasarkan level kedalaman tree
                // param 3 : mencetak "Output x:"
                printTreePreOrder(T.root, 0, ++prt);
            }
        }
        count++;
    } while(strcmp(query1, "DONE;") != 0);
    printf("=========\n");
    return 0;
}