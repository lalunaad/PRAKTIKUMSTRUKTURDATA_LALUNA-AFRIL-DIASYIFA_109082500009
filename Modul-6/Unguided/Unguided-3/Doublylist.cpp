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
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (!P) return;
    L.First = P->next;
    if (L.First) L.First->prev = nullptr;
    else L.Last = nullptr;
    P->next = nullptr;
}
void deleteLast(List &L, address &P) {
    P = L.Last;
    if (!P) return;
    L.Last = P->prev;
    if (L.Last) L.Last->next = nullptr;
    else L.First = nullptr;
    P->prev = nullptr;
}
void deleteAfter(address Prec, address &P) {
    P = nullptr;
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    P->prev = nullptr; P->next = nullptr;
}