#include "header.h"

int jumlahA(char str[]) {
    int jml = 0;
    for (int i = 0; i < strlen(str); i++) {
        if(str[i] == 'a') jml++;
    }
    return jml;
}

void swap(string *awal, string *akhir){
    /*
        * prosedur untuk menukar string dalam struct
        * digunakan dalam prosedur sorting
    */
    string temp; //------------------------------------> penampung sementara
    temp = *awal; //---------------------------------> string awal ditampung
    *awal = *akhir; //-------------------------------> string akhir dipindah ke string awal
    *akhir = temp; //--------------------------------> string tampungan dipindah ke string akhir
}

void selectionSort(string d[], int n){
    /*
        * prosedur selection sort
        * cara kerjanya adalah menukar string yang memenuhi kondisi
        * jika string idx > string ke-j maka terjadi penukaran nilai
    */
    int i, j, idx;
    //--------^ penanda index yg dicek
    //--^--^ iterator
    for (i = 0; i < n - 1; i++) {
        idx = i; //----------------------------------> inisialisasi nilai idx dengan i
        for (j = i + 1; j < n; j++) {
            if (d[idx].jmlA > d[j].jmlA) { //--------> jika string kiri > string kanan
                idx = j; //--------------------------> inisialisasi idx dengan posisi string kanan
            }
        }
        swap(&d[i], &d[idx]); //---------------------> tukar string ke-i dengan string ke-idx
    }
}