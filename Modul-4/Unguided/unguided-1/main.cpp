#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    address Pdel;

    deleteFirst(L, Pdel);
    dealokasi(Pdel);

    deleteLast(L, Pdel);
    dealokasi(Pdel);

    address Prec = L.first; 
    deleteAfter(L, Prec, Pdel);
    dealokasi(Pdel);

    printInfo(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}