#include "header.h"

int main() {
    // deklarasi variabel
    tree T;
    data tParent, tChild;
    int maxLen[50] = {0}; // inisialisasi seluruh nilai array ke nol
    int n = 0, m = 0;
    char str[250];
    simpul *nodeRoot;

    // meminta masukan jumlah daerah/simpul
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // meminta masukan query daerah parent, daerah child, jumlah korban
        // dipisahkan oleh karakter #
        scanf("%s", str);
        // memecah string masukan berdasarkan karakter pemisah
        explode(str, tParent.nama, tChild.nama, &tChild.korban, '#');

        if(strcmp(tParent.nama, "null") == 0) {
            // jika parent nya null, maka itu root teratas
            // untuk membuat tree
            makeTree(tChild, &T);
        } else {
            // jika parent nya bukan null, cari parent nya
            nodeRoot = findSimpul(tParent.nama, T.root);
            // tambahkan simpul anaknya
            addChild(tChild, nodeRoot);
        }
    }

    // hitung jumlah akumulasi korban dari simpul terbawah
    hitungKorban(T.root);

    // cari nama daerah terpanjang di setiap level
    maxLenName(T.root, 0, maxLen);
    int i = 1;
    while(maxLen[i+1] != 0) {
        maxLen[i] += maxLen[i - 1];
        i++;
    }
    maxLen[i] = 0;

    // cetak pohon lengkap
    printf("pohon lengkap:\n");
    printTreePreOrder(T.root, 0, maxLen);

    // meminta masukan jumlah sub pohon yg ingin dicetak
    scanf("%d", &m);
    printf("\nSub-pohon:\n");
    for (int j = 0; j < m; j++) {
        // diulang sebanyak permintaan jumlah sub pohon
        char subTree[100];
        scanf("%s", subTree); // meminta masukan daerah root sub pohon
        nodeRoot = findSimpul(subTree, T.root); // mencari root

        // inisialisasi maxlen ke nol
        for (int k = 0; k <= i; k++) {
            maxLen[k] = 0;
        }

        // mencari daerah terpanjang di setiap level pada root
        maxLenName(nodeRoot, 0, maxLen);
        i = 1;
        while(maxLen[i+1] != 0) {
            maxLen[i] += maxLen[i - 1];
            i++;
        }
        maxLen[i] = 0;

        // mencetak sub pohon
        printTreePreOrder(nodeRoot, 0, maxLen);
    }
    return 0;
}