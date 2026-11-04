#include <iostream>
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { L.First = nullptr; L.Last = nullptr; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr; P->prev = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.Last;
    while (P) {
        cout << "no polisi : " << P->info.nopol << '\n';
        cout << "warna     : " << P->info.warna << '\n';
        cout << "tahun     : " << P->info.thnBuat << '\n';
        P = P->prev;
    }
}
void insertLast(List &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.Last;
    if (L.Last) L.Last->next = P;
    else L.First = P;
    L.Last = P;
}
address findElm(List L, infotype x) {
    address P = L.First;
    while (P) {
        if (P->info.nopol == x.nopol) return P;
        P = P->next;
    }
    return nullptr;
}