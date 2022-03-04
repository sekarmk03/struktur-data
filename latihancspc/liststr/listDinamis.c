#include "header.h"

int main(){
    // deklarasi variable
    list L;
    createList(&L);
    char str[100];
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        addFirst(str, &L);
    }
    printElement(L);
    return 0;
}
