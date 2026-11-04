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
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> x.nopol;

    address target = findElm(L, x);
    address P = nullptr;
    if (target == nullptr) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan.\n";
        return 0;
    }

    if (target == L.First) {
        deleteFirst(L, P);
    } else if (target == L.Last) {
        deleteLast(L, P);
    } else {
        deleteAfter(target->prev, P);
    }

    cout << "Data dengan nomor polisi " << P->info.nopol << " berhasil dihapus.\n";
    dealokasi(P);

    cout << "\nDATA LIST 1\n\n";
    address Q = L.Last;
    while (Q) {
        cout << "Nomor Polisi : " << Q->info.nopol << '\n';
        cout << "Warna        : " << Q->info.warna << '\n';
        cout << "Tahun        : " << Q->info.thnBuat << '\n';
        Q = Q->prev;
    }
    return 0;
}