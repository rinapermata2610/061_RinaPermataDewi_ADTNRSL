/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include <iostream>
#include "spnrsll.h"

using namespace std;

int main() {
    List MyList;
    infotype X;
    address P, Prec;

    // 1) Buat List Kosong
    CreateList(&MyList);
    PrintInfo(MyList); // Output: List Kosong 

    // 2) Input 7 Sebagai Elemen Pertama
    InsVFirst(&MyList, 7);
    PrintInfo(MyList); // Output: 7

    // 3) Input 11 Sebagai Elemen Kedua (Insert Last)
    InsVLast(&MyList, 11);
    PrintInfo(MyList); // Output: 7 11

    // 4) Input 9 Diantara 7 dan 11 (Insert After 7)
    Prec = Search(MyList, 7);
    if (Prec != Nil) {
        P = Alokasi(9);
        InsertAfter(&MyList, P, Prec);
    }
    PrintInfo(MyList); // Output: 7 9 11

    // 5) Input 5 di Awal List (Insert First)
    InsVFirst(&MyList, 5);
    PrintInfo(MyList); // Output: 5 7 9 11

    // 6) Input 13 di Akhir List (Insert Last)
    InsVLast(&MyList, 13);
    PrintInfo(MyList); // Output: 5 7 9 11 13

    // 7) Hapus Elemen Terakhir (Bilangan 13)
    DelVLast(&MyList, &X);
    PrintInfo(MyList); // Output: 5 7 9 11

    // 8) Hapus Bilangan 7 Pada List
    P = Search(MyList, 7);
    if (P != Nil) {
        DelP(&MyList, 7);
    }
    PrintInfo(MyList); // Output: 5 9 11

    // 9) Hapus Elemen Pertama (Bilangan 5)
    DelVFirst(&MyList, &X);
    PrintInfo(MyList); // Output: 9 11

    // 10) Hapus Semua Elemen List
    while (!ListEmpty(MyList)) {
        DelVFirst(&MyList, &X);
    }
    
    DelAll(&MyList); // Menghapus semua elemen list
    PrintInfo(MyList); // Output: List Kosong

    return 0;
}