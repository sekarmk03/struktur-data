#include <stdio.h>
#include <string.h>

typedef struct {
    char str[50];
    int jmlA;
} string;

int jumlahA(char str[]);
void swap(string *awal, string *akhir);
void selectionSort(string d[], int n);