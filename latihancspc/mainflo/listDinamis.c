#include "header.h"

int main(){
    // deklarasi variable
    list L;
    createList(&L);
    float flo;
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &flo);
        addArange(flo, &L);
    }
    printElement(L);
    return 0;
}
