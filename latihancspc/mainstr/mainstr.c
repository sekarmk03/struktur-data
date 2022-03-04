#include "header.h"

int main() {
    int n = 0;
    scanf("%d", &n);
    string str[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i].str);
        str[i].jmlA = jumlahA(str[i].str);
    }
    selectionSort(str, n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i].str);
    }
    return 0;
}