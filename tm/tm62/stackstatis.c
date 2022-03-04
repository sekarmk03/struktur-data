#include "header.h"

int main() {
    stack S1, S2;
    createEmpty(&S1);
    createEmpty(&S2);
    char nama[50], harga[50];
    printStack(S1, "S1");
    printStack(S2, "S2");
    printf("==================\n");
    scanf("%s%s", nama, harga);
    push(nama, harga, &S1);
    scanf("%s%s", nama, harga);
    push(nama, harga, &S2);
    scanf("%s%s", nama, harga);
    push(nama, harga, &S2);
    printStack(S1, "S1");
    printStack(S2, "S2");
    printf("==================\n");
    pop(&S1);
    popPush(&S2, &S1);
    scanf("%s%s", nama, harga);
    push(nama, harga, &S1);
    scanf("%s%s", nama, harga);
    push(nama, harga, &S2);
    scanf("%s%s", nama, harga);
    push(nama, harga, &S1);
    pop(&S2);
    popPush(&S1, &S2);
    printStack(S1, "S1");
    printStack(S2, "S2");
    printf("==================\n");
    return 0;
}