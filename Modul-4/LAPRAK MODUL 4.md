# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Laluna Afril Diasyifa - 109082500009</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas [1, 2]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer [1, 3]. Pada dasarnya, pengalokasian memori secara dinamis pada linked list memungkinkan penggunaan memori yang lebih efisien dibandingkan array yang bersifat statis, terutama saat menangani penambahan atau pengurangan data secara instan [2, 4].

### A. Singly Linked List<br/>
Singly linked list adalah struktur data linear yang tersusun dari node-node yang saling terhubung melalui pointer [1]. Penelusuran pada singly linked list hanya bisa dilakukan satu arah, dari awal hingga akhir list [1, 2].

#### 1. Konsep Node
Setiap node pada singly linked list terdiri dari komponen info untuk menyimpan data dan next untuk menyimpan alamat node berikutnya [1].

#### 2. Penelusuran Satu Arah
Penelusuran elemen dilakukan secara linier dan sekuensial hanya dari elemen pertama hingga elemen terakhir [1, 3].

### B. Komponen List<br/>
Komponen utama dalam pengoperasian list meliputi pointer penunjuk dan nilai penanda akhir [1].
#### 1. Pointer First
ointer First berfungsi menunjuk ke node pertama dari linked list [1].
#### 2. Penanda Akhir List (Nil)
Node terakhir memiliki pointer next yang bernilai Nil atau NULL sebagai penanda akhir dari list [1, 2].
#### 3. Kondisi List Kosong
List dikatakan dalam keadaan kosong apabila pointer First bernilai Nil [1].

### C. Alokasi Memori Dinamis<br/>
Pengalokasian memori pada linked list dilakukan secara dinamis selama program berjalan [1, 4].
#### 1. Penggunaan Operator Memori
Node pada linked list dialokasikan secara dinamis menggunakan operator new dan dibebaskan dari memori menggunakan delete [1, 4].
#### 2. Fleksibilitas Ukuran List
Penggunaan memori dinamis membuat ukuran list bersifat fleksibel sesuai dengan kebutuhan data [1, 2].
#### 3. Efisiensi Manipulasi Data
Penyisipan atau penghapusan elemen dapat dilakukan tanpa perlu menggeser posisi elemen lain seperti pada array [1, 3].

### D. Abstract Data Type (ADT)<br/>
ADT adalah pendefinisian tipe data beserta operasi-operasi dasar yang dapat dilakukan terhadap tipe data tersebut [1, 2].
#### 1. Struktur File Singlylist.h
Digunakan untuk menyimpan deklarasi struktur tipe data, pointer, dan pustaka prosedur/fungsi [1].
#### 2. Struktur File Singlylist.cpp
Berisi implementasi detail dari seluruh prosedur dan fungsi operasi dasar list [1].
#### 3. Struktur File main.cpp
Merupakan program utama tempat pemanggilan fungsi dan pengujian operasi linked list [1].

### E. Operasi Dasar<br/>
Operasi dasar digunakan untuk pembentukan, alokasi, penyisipan, dan penayangan data list [1].
#### 1. Pembentukan dan Alokasi Node
Prosedur createList berfungsi membuat list kosong, alokasi untuk membuat node baru, dan dealokasi untuk membebaskan memori node [1].
#### 2. Penyisipan Elemen (insertFirst)
Penyisipan elemen dilakukan di posisi paling depan list sehingga membalikkan urutan masukan data [1, 2].
#### 3. Penayangan dan Contoh Luaran
Fungsi printInfo menampilkan seluruh isi list. Data masukan berurutan 2, 0, 8, 12, 9 dengan insertFirst akan menghasilkan luaran list 9, 12, 8, 0, 2 [1].

### F. Operasi Penghapusan<br/>
Operasi penghapusan digunakan untuk mengeluarkan elemen dari list dan membebaskan memorinya [1].
#### 1. Operasi deleteFirst
Prosedur untuk menghapus node pertama yang ditunjuk oleh First [1].
#### 2. Operasi deleteLast
Prosedur untuk menghapus node terakhir dengan bantuan pencarian node sebelumnya [1].
#### 3. Operasi deleteAfter
Prosedur untuk menghapus node yang berada tepat setelah node tertentu dengan memperhatikan urutan perubahan pointer agar list tidak terputus [1].

### G. Penghitungan dan Penghapusan Seluruh List<br/>
Operasi pemrosesan seluruh elemen digunakan untuk mengukur dan membersihkan memori list [1].
#### 1. Penghitungan Elemen (nbList)
Operasi pemrosesan seluruh elemen digunakan untuk mengukur dan membersihkan memori list [1].
#### 2. Penghapusan Seluruh List (deleteList)
Prosedur deleteList menghapus seluruh node satu per satu sampai list menjadi kosong [1].
#### 3. Pencegahan Kebocoran Memori
Penghapusan seluruh node secara sistematis dilakukan guna mencegah terjadinya kebocoran memori (memory leak) [1, 4].

## Guided 

### 1. list.h

```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```

### 2. list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. Menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

### 3. main.cpp

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
List (linked list) adalah bentuk struktur data linear yang tersusun dari sekumpulan node dinamis yang saling terhubung melalui pointer. Setiap node menyimpan data serta alamat node berikutnya, sehingga memungkinkan penambahan dan penghapusan elemen secara fleksibel tanpa harus menggeser posisi data lain seperti pada array.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”. Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp” dengan implementasi.

### 1. singlylist.h

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```
### 2. singlylist.cpp

```C++
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
```
### 3. main.cpp

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Berdasarkan soal Unguided 1, kita diminta untuk membangun struktur data Singly Linked List menggunakan Abstract Data Type (ADT) yang terbagi menjadi tiga file utama: membuat file header Singlylist.h untuk mendeklarasikan tipe data dan prototipe fungsi, membuat file implementasi Singlylist.cpp untuk menuliskan logika prosedur manajemen memori serta operasi dasar seperti penyisipan dan penghapusan node, serta membuat file program utama main.cpp guna menguji jalannya fungsi-fungsi tersebut dengan memasukkan serangkaian data angka menggunakan insertFirst, menghapus beberapa node, menghitung jumlah node yang tersisa dengan nbList, dan membersihkan seluruh memori list di akhir program. 

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

### 1. singly.h

```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif
```
### 2. singly.cpp

```C++
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P -> info = x;
    P -> next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P -> next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        P = L.First;
        L.First = P -> next;
        P -> next = Nil;
    } else {
       P = Nil; 
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First -> next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q -> next -> next != Nil) {
            Q = Q -> next;
        }
        P = Q -> next;
        Q -> next = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec -> next != Nil) {
        P = Prec -> next;
        Prec -> next = P -> next;
        P -> next = Nil;
    } else {
        P = Nil;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P -> next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```
### 3. main.cpp

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    address P;
    createList(L);

    P1 = alokasi(2); insertFirst(L, P1);
    P2 = alokasi(0); insertFirst(L, P2);
    P3 = alokasi(8); insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9); insertFirst(L, P5);

    deleteFirst(L, P);
    dealokasi(P);

    deleteLast(L, P);
    dealokasi(P);

    deleteAfter(L, P4, P);
    dealokasi(P);

    printInfo(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    cout << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program pada Unguided 2 melanjutkan implementasi Singly Linked List dengan fokus melakukan uji coba berbagai fungsi penghapusan node. Berdasarkan program utama (main.cpp), list awalnya diisi dengan nilai 2, 0, 8, 12, dan 9 menggunakan metode insertFirst sehingga menghasilkan urutan awal 9 12 8 0 2. Selanjutnya, program menghapus node pertama (9) menggunakan deleteFirst(), menghapus node terakhir (2) menggunakan deleteLast(), serta menghapus node setelah P4 (yakni nilai 8) menggunakan deleteAfter(). Setelah proses penghapusan tersebut, sisa elemen list ditampilkan menggunakan printInfo(L), jumlah node yang tersisa dihitung menggunakan nbList(L), dan seluruh memori list akhirnya dibersihkan menggunakan deleteList(L) untuk mencegah terjadinya memory leak.


## Kesimpulan
Secara keseluruhan, praktikum Modul 4 ini membahas implementasi Singly Linked List menggunakan Abstract Data Type (ADT) yang terbagi secara modular ke dalam file header, file implementasi, dan program utama. Melalui percobaan Guided (yang mengelola data majemuk/record mahasiswa) hingga Unguided 1 dan 2 (yang mengelola data integer dengan berbagai variasi operasi insert dan delete), dapat dipahami bahwa linked list merupakan struktur data dinamis yang sangat fleksibel karena memanfaatkan pointer serta alokasi memori dinamis (new dan delete). Selain itu, pemahaman mengenai manajemen pointer sangat krusial dalam menjaga keutuhan sambungan antar node saat melakukan penambahan maupun penghapusan elemen, serta pentingnya penggunaan fungsi pembersihan (deleteList) di akhir program guna mencegah terjadinya kebocoran memori (memory leak).

## Referensi
[1] Laboratorium Informatika, Modul 4 Praktikum Struktur Data: Singly Linked List. Bandung, Indonesia: Telkom University, 2026.
<br>...
