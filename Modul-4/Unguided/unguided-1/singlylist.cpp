#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = P->next;
    P->next = Nil;
}

void deleteLast(List &L, address &P) {
    if (L.first->next == Nil) {
        P = L.first;
        L.first = Nil;
    } else {
        address Q = L.first;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = Nil;
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}