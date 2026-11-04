# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Laluna Afril Diasyifa - 109082500009</p>

## Dasar Teori
Doubly linked list atau yang disebut juga senarai berantai ganda adalah salah satu variasi struktur data linked list yang mana setiap elemennya menyimpan data sekaligus dua buah penunjuk (pointer/successor) yang mengacu pada elemen sebelum (prev) dan elemen sesudahnya (next)[1]. Keberadaan dua pointer tersebut memungkinkan traversal data dilakukan secara dua arah, baik maju (forward) maupun mundur (backward), sehingga memberikan fleksibilitas akses yang lebih baik dibandingkan singly linked list[2]. Struktur data ini umumnya dikelola menggunakan pointer utama yaitu first untuk menunjuk elemen pertama dan last untuk menunjuk elemen terakhir[1].

### A. Komponen dan Struktur Doubly Linked List<br/>
Doubly linked list dibangun atas beberapa komponen utama yang saling mendukung operasi navigasi serta penyimpanan data di dalamnya[1].
#### 1. Pointer Elemen (next dan prev)
Setiap elemen (node) pada doubly linked list terdiri dari bidang data (info) dan dua pointer successor, yaitu next yang mengarah ke elemen berikutnya serta prev yang mengarah ke elemen sebelumnya[1]. Pointer prev pada elemen pertama dan pointer next pada elemen terakhir biasanya menunjuk ke nilai NULL (Nil)[1].
#### 2. Pointer Header List (first dan last)
Struktur data list menggunakan dua variabel penunjuk utama, yakni first yang bertindak sebagai gerbang akses elemen awal dan last sebagai gerbang akses elemen akhir[1]. Suatu list dikatakan kosong jika variabel first bernilai Nil[1].
#### 3. Implementasi Struct C++
Representasi fisik doubly linked list dalam bahasa C++ diwujudkan menggunakan tipe data bentukan (struct) yang mendefinisikan tipe informasi data (infotype), struktur elemen (node), serta struktur list utama[1].

### B. Operasi Manipulasi Elemen (Insertion dan Deletion)<br/>
Operasi pada doubly linked list mencakup penambahan (insertion) dan penghapusan (deletion) elemen dengan penyesuaian sambungan pointer[1, 3].
#### 1. Operasi Insertion (Insert First, Last, dan After/Before)
Proses penambahan elemen dapat dilakukan pada awal list (insert first), akhir list (insert last), maupun setelah/sebelum elemen tertentu (insert after/before)[2, 3]. Penambahan elemen baru memerlukan alokasi memori serta penyesuaian dua sambungan pointer (next dan prev) agar keterhubungan elemen tetap terjaga secara linier dan konstan[1, 2].
#### 2. Operasi Deletion (Delete First, Last, dan After/Before)
Proses penghapusan elemen dilakukan dengan melepaskan tautan pointer next dan prev dari elemen yang bersangkutan, diikuti oleh pembaruan pointer first atau last jika elemen yang dihapus berada di ujung list[3, 4]. Elemen yang telah dilepas selanjutnya dapat didealokasi dari memori sistem[4, 5].
#### 3. Operasi Pencarian dan Traversing (Searching, Update, View)
Akses data pada doubly linked list lebih fleksibel dibandingkan singly linked list karena pencarian (searching) dan pencetakan data (view) dapat diproses dari depan ke belakang maupun dari belakang ke depan secara langsung berkat penunjuk linier ganda[6].

## Guided 1

### 1. Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct barang {
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist { infotype info; address prev; address next; };
struct list { address first; address last; };

void CreateList(list &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address R, address P);
void insertBefore(list &L, address R, address P);
void printInfo(const list &L);
address findElm(const list&L, const string &kode);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address prec, address &P);
void deleteBefore(list &L, address succ, address &P);
#endif
```


### 2. Doublylist.cpp

```C++
#include <iostream>
#include <iomanip>
#include "Doublylist.h"
using namespace std;

void CreateList(list &L) { L.first = nullptr; L.last = nullptr; }

address alokasi(const infotype &x) {
    address P = new elmlist;
    P->info = x;
    P->prev = nullptr; P->next = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void insertFirst(list &L, address P) {
    if (!P) return;
    P->prev = nullptr; P->next = L.first;
    if (L.first) L.first->prev = P;
    else L.last = P;
    L.first = P;
}
void insertLast(list &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.last;
    if (L.last) L.last->next = P;
    else L.first = P;
    L.last = P;
}

// Menyisipkan P tepat setelah R.
void insertAfter(list &L, address R, address P) {
    if (!R || !P) return;
    P->prev = R;
    P->next = R->next;
    if (R->next) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

// Menyisipkan P tepat sebelum R.
void insertBefore(list &L, address R, address P) {
    if (!R || !P) return;
    P->next = R;
    P->prev = R->prev;
    if (R->prev) R->prev->next = P;
    else L.first = P;
    R->prev = P;
}
void printInfo(const list &L) {
    address P = L.first;
    if (!P) {
        cout << "List kosong.\n";
        return;
    }

    cout << "+--------+------------+-------+\n";
    cout << "| Kode   | Nama       | Tahun |\n";
    cout << "+--------+------------+-------+\n";
    while (P) {
        cout << "| " << left << setw(6) << P->info.kode
             << " | " << setw(10) << P->info.nama
             << " | " << setw(5) << P->info.tahun << " |\n";
        P = P->next;
    }
    cout << "+--------+------------+-------+\n";
}
address findElm(const list &L, const string &kode) {
    address P = L.first;
    while (P) {
        if (P->info.kode == kode) return P;
        P = P->next;
    }
    return nullptr;
}
void deleteFirst(list &L, address &P) {
    if (!L.first) { P = nullptr; return; }
    P = L.first; L.first = P->next;
    if (L.first) L.first->prev = nullptr;
    else L.last = nullptr;
    P->prev = P->next = nullptr;
}
void deleteLast(list &L, address &P) {
    if (!L.last) { P = nullptr; return; }
    P = L.last; L.last = P->prev;
    if (L.last) L.last->next = nullptr;
    else L.first = nullptr;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat setelah prec.
void deleteAfter(list &L, address prec, address &P) {
    P = nullptr;
    if (!prec || !prec->next) return;
    P = prec->next; prec->next = P->next;
    if (P->next) P->next->prev = prec;
    else L.last = prec;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat sebelum succ.
void deleteBefore(list &L, address succ, address &P) {
    P = nullptr;
    if (!succ || !succ->prev) return;
    P = succ->prev; succ->prev = P->prev;
    if (P->prev) P->prev->next = succ;
    else L.first = succ;
    P->prev = P->next = nullptr;
}
```


### 3. main.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void tampilkanJudul(const string &judul) {
    cout << "\n========================================\n";
    cout << judul << '\n';
    cout << "========================================\n";
}

int main() {
    list L;
    CreateList(L);

    infotype barang1 = {"B001", "Laptop", 2020};
    infotype barang2 = {"B002", "Monitor", 2022};
    infotype barang3 = {"B003", "Keyboard", 2023};
    infotype barang4 = {"B004", "Mouse", 2024};

    address P = nullptr;
    address posisi = nullptr;

    cout << "DEMONSTRASI OPERASI DOUBLY LINKED LIST\n";
    cout << "Data yang digunakan: B001, B002, B003, dan B004\n";

    tampilkanJudul("[1] INSERT FIRST");
    cout << "Menambahkan B002 di awal list.\n";
    insertFirst(L, alokasi(barang2));
    printInfo(L);

    tampilkanJudul("[2] INSERT LAST");
    cout << "Menambahkan B004 di akhir list.\n";
    insertLast(L, alokasi(barang4));
    printInfo(L);

    tampilkanJudul("[3] INSERT AFTER");
    cout << "Menambahkan B003 setelah B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertAfter(L, posisi, alokasi(barang3));
    }
    printInfo(L);

    tampilkanJudul("[4] INSERT BEFORE");
    cout << "Menambahkan B001 sebelum B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertBefore(L, posisi, alokasi(barang1));
    }
    printInfo(L);

    tampilkanJudul("[5] FIND ELEMENT");
    cout << "Mencari barang dengan kode B003.\n";
    posisi = findElm(L, "B003");
    if (posisi != nullptr) {
        cout << "Data ditemukan:\n";
        cout << "  Kode  : " << posisi->info.kode << '\n';
        cout << "  Nama  : " << posisi->info.nama << '\n';
        cout << "  Tahun : " << posisi->info.tahun << '\n';
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    tampilkanJudul("[6] DELETE AFTER");
    cout << "Menghapus node setelah B002 (B003).\n";
    posisi = findElm(L, "B002");
    deleteAfter(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[7] DELETE BEFORE");
    cout << "Menghapus node sebelum B004 (B002).\n";
    posisi = findElm(L, "B004");
    deleteBefore(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[8] DELETE FIRST");
    cout << "Menghapus node pertama.\n";
    deleteFirst(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[9] DELETE LAST");
    cout << "Menghapus node terakhir.\n";
    deleteLast(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("SELESAI");
    cout << "Kondisi list: "
         << (L.first == nullptr && L.last == nullptr ? "kosong.\n" : "masih berisi data.\n");

    return 0;
}
```
Program di atas merupakan implementasi struktur data Doubly Linked List dalam bahasa C++ yang memanfaatkan dua pointer (next dan prev) pada setiap elemennya agar navigasi data bisa dilakukan secara maju maupun mundur. Kode program ini dibagi menjadi tiga bagian utama, yaitu file header (Doublylist.h) untuk deklarasi struct dan purwarupa fungsi, file implementasi (Doublylist.cpp) untuk logika kode manipulasi data seperti insert, delete, searching, dan print, serta driver file (main.cpp) guna mengeksekusi dan menguji seluruh operasi tersebut secara berurutan.

## Unguided 

#### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:
```text
Type infotype : kendaraan <
 nopol : string
 warna : string
 thnBuat : integer
>
Type address : pointer to ElmList
Type ElmList <
 info : infotype
 next :address
 prev : address
>
Type List <
 First : address
 Last : address
>
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertLast(input/output L : List, 
 input P : address )
```
#### Ekspektasi Output
```text
masukkan nomor polisi: D001
masukkan warna kendaraan: hitam
masukkan tahun kendaraan: 90

masukkan nomor polisi: D003
masukkan warna kendaraan: putih
masukkan tahun kendaraan: 70

masukkan nomor polisi: D001
masukkan warna kendaraan: merah
masukkan tahun kendaraan: 80
nomor polisi sudah terdaftar

masukkan nomor polisi: D004
masukkan warna kendaraan: kuning
masukkan tahun kendaraan: 90

DATA LIST 1
no polisi : D004
warna     : kuning
tahun     : 90
no polisi : D003
warna     : putih
tahun     : 70
no polisi : D001
warna     : hitam
tahun     : 90
```
### 1. Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

#endif
```
### 2. Doublylist.cpp

```C++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        (L.Last)->next = P;
        L.Last = P;
    }
}
```
### 3. main.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    infotype x;
    address P;
    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        bool ada = false;
        P = L.First;
        while (P != Nil && !ada) {
            if (P->info.nopol == x.nopol) {
                ada = true;
            }
            P = P->next;
        }

        if (ada) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program di atas merupakan implementasi studi kasus Doubly Linked List untuk mengelola data kendaraan berupa nomor polisi, warna, dan tahun buat. Program ini dilengkapi dengan fitur validasi agar nomor polisi yang sama tidak dapat diinputkan dua kali serta menggunakan metode penelusuran mundur dari pointer Last untuk mencetak data sesuai dengan ekspektasi output.

#### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru.
#### fungsi findElm( L : List, x : infotype ) : address
#### Ekspektasi Output:
```text
Masukkan Nomor Polisi yang dicari  : D001

Nomor Polisi : D001
Warna        : hitam
Tahun        : 90
```
### 1. Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

using infotype = kendaraan;
struct ElmList;
using address = ElmList*;
struct ElmList { infotype info; address next; address prev; };
struct List { address First; address Last; };

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);
#endif
```
### 2. Doublylist.cpp

```C++
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
```
### 3. main.cpp

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program di atas merupakan implementasi fungsi searching (findElm) pada Doubly Linked List untuk mencari data kendaraan berdasarkan nomor polisi yang diinputkan oleh pengguna. Jika data ditemukan, program akan menampilkan detail informasi kendaraan tersebut (nomor polisi, warna, dan tahun) sesuai dengan ekspektasi output.

#### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.
- procedure deleteFirst( input/output L : List, 
 P : address )
- procedure deleteLast( input/output L : List, 
 P : address )
- procedure deleteAfter( input Prec : address, 
 input/output P : address )
#### Ekspektasi Output:
```text
Masukkan Nomor Polisi yang akan dihapus : D003
Data dengan nomor polisi D003 berhasil dihapus.

DATA LIST 1
Nomor Polisi : D004
Warna        : kuning
Tahun        : 90
Nomor Polisi : D001
Warna        : hitam
Tahun        : 90
```
### 1. Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

using infotype = kendaraan;
struct ElmList;
using address = ElmList*;
struct ElmList { infotype info; address next; address prev; };
struct List { address First; address Last; };

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
#endif

```
### 2. Doublylist.cpp

```C++


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
```
### 3. main.cpp

```C++
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
  
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program di atas merupakan implementasi operasi penghapusan data (deletion) pada Doubly Linked List berdasarkan nomor polisi kendaraan yang diinputkan pengguna. Program memanfaatkan prosedur deleteFirst, deleteLast, dan deleteAfter untuk menangani posisi data yang akan dihapus (baik di awal, di akhir, maupun di tengah list), lalu mendealokasi memori serta menampilkan sisa data secara mundur (backward traversal) sesuai ekspektasi output.

## Kesimpulan
Kesimpulan dari praktikum ini adalah Doubly Linked List merupakan struktur data linier yang setiap elemennya memiliki dua pointer (next dan prev), sehingga memungkinkan navigasi data secara dua arah baik maju maupun mundur. Berdasarkan hasil praktikum, operasi manipulasi data seperti penambahan elemen (insert), pencarian (searching), hingga penghapusan (delete) pada berbagai posisi dapat diimplementasikan dengan sukses dalam bahasa C++ melalui pembaruan pointer First dan Last secara tepat untuk menjaga integritas data.

## Referensi
Laboratorium Informatika, Fakultas Informatika, Telkom University. (t.t.). Modul 6: Doubly linked list (bagian pertama). Dalam Modul praktikum struktur data (hlm. 51–58). Telkom University.