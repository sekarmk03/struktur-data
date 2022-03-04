#include "header.h"

int main(){
    graph G;
    createEmpty(&G);
    simpul *begin;
    simpul *end; 
    addSimpul(1, &G);
    addSimpul(2, &G);
    addSimpul(3, &G);
    addSimpul(4, &G);
    addSimpul(5, &G);
    addSimpul(6, &G);
    addSimpul(7, &G);
    addSimpul(8, &G);
    begin = findSimpul(1, G);
    end = findSimpul(2, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    end = findSimpul(3, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    begin = findSimpul(4, G);
    end = findSimpul(5, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    begin = findSimpul(6, G);
    end = findSimpul(7, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    begin = findSimpul(7, G);
    end = findSimpul(5, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    begin = findSimpul(8, G);
    end = findSimpul(1, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    end = findSimpul(4, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    end = findSimpul(6, G);
    if((begin != NULL) && (end != NULL)) {
        addJalur(begin, end);
    }
    printGraph(G);
    printf("===========\n");
    int hapus;
    scanf("%d", &hapus);
    delSimpul(hapus, &G);
    printGraph(G);
    return 0;
}