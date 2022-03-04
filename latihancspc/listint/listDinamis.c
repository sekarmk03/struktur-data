#include "header.h"

int main(){
    // deklarasi variable
    list L;
    createList(&L);
    int intgr = 0;
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &intgr);
        addFirst(intgr, &L);
    }
    printElement(L);
    return 0;
}
