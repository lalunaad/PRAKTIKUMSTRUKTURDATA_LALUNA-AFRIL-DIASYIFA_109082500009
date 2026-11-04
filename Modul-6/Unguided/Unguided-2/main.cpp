#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    insertLast(L, alokasi({"D001", "hitam", 90}));
    insertLast(L, alokasi({"D003", "putih", 70}));
    insertLast(L, alokasi({"D004", "kuning", 90}));

    infotype x;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> x.nopol;
    address P = findElm(L, x);
    cout << '\n';
    if (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << '\n';
        cout << "Warna        : " << P->info.warna << '\n';
        cout << "Tahun        : " << P->info.thnBuat << '\n';
    } else {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan.\n";
    }
    return 0;
}