# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Laluna Afril Diasyifa - 109082500009</p>

## Dasar Teori
Linked list atau senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer. Pada singly linked list, setiap node (ElmList) hanya memiliki satu pointer, yaitu next yang menunjuk ke node berikutnya, di samping info yang menyimpan data[2]. List direpresentasikan oleh pointer first dan dinyatakan kosong jika L.first = Nil. Seluruh operasinya dikemas sebagai Abstract Data Type (ADT) di file *.h dan *.cpp, dengan CreateList untuk membentuk list kosong, alokasi untuk membuat node baru, dan dealokasi untuk mengembalikan memori ke sistem[3].

### A. Operasi Pencarian (Searching)<br/>
Searching adalah operasi dasar untuk mencari node tertentu dengan mengunjungi tiap node dari first sampai ditemukan atau sampai Nil, dengan kompleksitas O(n) pada kasus terburuk[4]. Hasil pencarian mempermudah operasi insert after, delete after, dan update.
#### 1. findElm
findElm(L, X) mengembalikan alamat elemen yang info-nya sama dengan X, atau Nil jika tidak ditemukan.
#### 2. fFindElm
fFindElm(L, P) mengembalikan true jika elemen beralamat P ada di list, dan false jika tidak ada.
#### 3. findBefore
findBefore(L, P) mengembalikan alamat elemen sebelum P, atau Nil jika P berada di awal list.

### B. Penyisipan di Akhir (Insert Last)<br/>
Penyisipan menambahkan elemen yang sudah dialokasikan ke dalam list dengan mengatur ulang pointer next[2]. Penyisipan di akhir memerlukan traversal sampai elemen yang next-nya Nil.
#### 1. insertFirst
insertFirst(L, P) menempatkan P di awal list, sehingga P->next menunjuk ke L.first dan L.first menunjuk ke P.
#### 2. insertAfter
insertAfter(L, P, Prec) menempatkan P setelah elemen Prec, sehingga P->next menunjuk ke Prec->next dan Prec->next menunjuk ke P.
#### 3. .insertLast
insertLast(L, P) menempatkan P di akhir list dengan mengarahkan next elemen terakhir ke P.

### C. Operasi Penghapusan (Delete)<br/>
Penghapusan melepas hubungan pointer suatu elemen dari list, lalu elemen tersebut didealokasi[3]. Setelah penghapusan, list dapat menjadi kosong.
#### 1. delFirst dan delLast
delFirst(L, P) menghapus elemen pertama, dan delLast(L, P) menghapus elemen terakhir. Pada keduanya, P menyimpan alamat elemen yang dilepas.
#### 2. delAfter
delAfter(L, P, Prec) menghapus elemen setelah Prec (Prec->next) dengan mengalihkan Prec->next ke elemen sesudahnya.
#### 3. delP
delP(L, X) mencari elemen yang info-nya sama dengan X, lalu menghapus dan mendealokasinya. Jika tidak ada, list tidak berubah.


### D. Operasi Lain (printInfo, nbList, delAll, dll)<br/>
Selain penyisipan dan penghapusan, ADT menyediakan operasi untuk memproses seluruh elemen list melalui traversal, yaitu mengunjungi node dari first sampai Nil[2].
#### 1. printInfo dan nbList
printInfo(L) menampilkan seluruh info pada list, dan nbList(L) mengembalikan jumlah elemennya.
#### 2. delAll dan invertList
delAll(L) menghapus dan mendealokasi semua elemen, sedangkan invertList(L) membalik urutan elemen list.
#### 3. copyList dan fCopyList
copyList(L1, L2) membuat L2 menunjuk ke elemen yang sama dengan L1, sedangkan fCopyList(L) mengembalikan list yang merupakan salinan dari L.

## Guided 

### 1. listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

### 2. listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

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
Program Guided 1 membuat *singly linked list* berisi data buah (nama, jumlah, harga) dengan ADT yang dipisah ke `listBuah.h`, `listBuah.cpp`, dan `main.cpp`. Program menambah lima *node* (insert), mengubah datanya (update), mencari *node* berdasarkan nama, alamat, dan rentang harga (searching), lalu menghapus *node* (delete) hingga seluruh *list* dikosongkan, dengan hasil tiap tahap ditampilkan lewat `printList` dan `nbList`.

## Unguided 

#### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”:
```
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
info : infotype
next : address
>
Type List : < First : address >
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst(input/output L : List, input P :address)
```
#### Cobalah hasil implementasi ADT pada file “main.cpp"
```
int main()
{
List L;
address P1, P2, P3, P4, P5 = Nil;
createList(L);
P1 = alokasi(2);
insertFirst(L,P1);
P2 = alokasi(0);
insertFirst(L,P2);
P3 = alokasi(8);
insertFirst(L,P3);
P4 = alokasi(12);
insertFirst(L,P4);
P5 = alokasi(9);
insertFirst(L,P5);
printInfo(L)
return 0;
}
```
#### Ekspektasi Output:
```text
9 12 8 0 2
Process returned 0 (0x0)    execution time: 0.019 s
Press any key to continue
```
#### singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

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

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```
#### singlylist.cpp

```C++
#include "singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
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

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

#### main.cpp
```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList;

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
    
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-5/Output/output%201%20-%20modul%205.png?raw=true)

Pada unguided 1, dibuat ADT Singly Linked List yang dipisah menjadi tiga file, yaitu singlylist.h untuk deklarasi struktur dan prototipe fungsi, singlylist.cpp untuk isi fungsinya, dan main.cpp untuk menguji program. Struktur datanya terdiri dari ElmList sebagai elemen yang menyimpan info dan penunjuk next ke elemen berikutnya, serta List yang memiliki First sebagai penunjuk elemen paling depan. Prosedur CreateList membuat list kosong dengan mengisi First dengan Nil, alokasi membuat elemen baru dan mengisi datanya, dealokasi menghapus elemen dari memori, printInfo menampilkan isi list dari First sampai bertemu Nil, dan insertFirst menambahkan elemen di awal list dengan menyambungkan next elemen baru ke First, lalu menjadikan elemen baru tersebut sebagai First. Pada main.cpp, data 2, 0, 8, 12, dan 9 dimasukkan satu per satu menggunakan insertFirst, sehingga data yang masuk belakangan berada paling depan dan menghasilkan output 9 12 8 0 2 sesuai ekspektasi soal. Perlu diperbaiki bahwa pada main.cpp tertulis CreateList; yang seharusnya CreateList(L); agar prosedurnya benar-benar dijalankan.

### 2. Carilah elemen dengan info 8 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

#### singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

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
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);

#endif
```

#### singlylist.cpp

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

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```

#### main.cpp

```C++
#include "Singlylist.h"

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

    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-5/Output/output%202%20-modul%205.png?raw=true)

Pada unguided 2, ditambahkan fungsi baru bernama `findElm` pada ADT Singly Linked List untuk mencari elemen dengan info tertentu, yaitu 8. Fungsi ini dideklarasikan di `singlylist.h` dan diisi di `singlylist.cpp`. Cara kerjanya, dibuat penunjuk bantu `P` yang dimulai dari `first`, lalu list ditelusuri elemen demi elemen. Jika `info` elemen yang sedang ditunjuk sama dengan nilai yang dicari, fungsi langsung mengembalikan alamat elemen tersebut. Jika sampai akhir list tidak ditemukan, fungsi mengembalikan `Nil`. Pada `main.cpp`, data 2, 0, 8, 12, dan 9 dimasukkan menggunakan `insertFirst`, sehingga urutan list menjadi 9, 12, 8, 0, 2. Setelah itu `findElm(L, 8)` dipanggil dan hasilnya disimpan di variabel `hasil`. Karena elemen dengan info 8 ada di dalam list, `hasil` tidak bernilai `Nil` dan program menampilkan output `8 ditemukan dalam list`. Jika elemen yang dicari tidak ada, program akan menampilkan `8 tidak ditemukan dalam list`.

### 3. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

##### singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

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
void printInfo(List L);
void insertFirst(List &L, address P);
int totalInfo(List L);

#endif
```
##### singlylist.cpp
```C++
#include "singlylist.h"

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

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
```
##### main.cpp
```C++
#include "singlylist.h"

int main() {
    List L;
    address P1 = Nil, P2 = Nil, P3 = Nil, P4 = Nil, P5 = Nil;
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

    cout << "Total info dari kelima elemen adalah " << totalInfo(L) << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-5/Output/output%203%20-%20modul%205.png?raw=true)

Pada unguided 3, ditambahkan fungsi baru bernama `totalInfo` pada ADT Singly Linked List untuk menghitung jumlah seluruh info dari elemen yang ada di dalam list. Fungsi ini dideklarasikan di `singlylist.h` dan diisi di `singlylist.cpp`. Cara kerjanya, dibuat variabel `total` yang awalnya bernilai 0 dan penunjuk bantu `P` yang dimulai dari `first`. List kemudian ditelusuri elemen demi elemen, dan pada setiap elemen nilai `info` ditambahkan ke `total`, lalu `P` berpindah ke elemen berikutnya. Proses ini berhenti ketika `P` bernilai `Nil`, yang berarti seluruh elemen sudah dijumlahkan, kemudian nilai `total` dikembalikan. Pada `main.cpp`, data 2, 0, 8, 12, dan 9 dimasukkan menggunakan `insertFirst`, sehingga urutan list menjadi 9, 12, 8, 0, 2. Setelah itu `totalInfo(L)` dipanggil dan hasilnya ditampilkan, yaitu 9 + 12 + 8 + 0 + 2 = 31, sehingga output yang muncul adalah `Total info dari kelima elemen adalah 31`.

## Kesimpulan
Berdasarkan praktikum modul ini, dapat disimpulkan bahwa Singly Linked List adalah struktur data yang setiap elemennya saling terhubung melalui penunjuk `next`, dengan `first` sebagai penunjuk elemen paling depan. Pemisahan program menjadi `singlylist.h`, `singlylist.cpp`, dan `main.cpp` membuat kode lebih rapi dan mudah dikembangkan. Operasi dasar seperti `createList`, `alokasi`, `dealokasi`, `printInfo`, dan `insertFirst` berhasil diimplementasikan, di mana `insertFirst` menyebabkan data yang masuk belakangan berada paling depan. Fungsi tambahan `findElm` dan `totalInfo` menunjukkan bahwa pencarian dan penjumlahan elemen dilakukan dengan menelusuri list satu per satu menggunakan penunjuk bantu, sehingga ketelitian dalam mengatur penunjuk sangat penting agar program berjalan dengan benar.

## Referensi
Tim Asisten Laboratorium Struktur Data. (2024). Modul 5: Singly Linked List (Bagian Kedua). Bandung: Fakultas Informatika, Telkom University.