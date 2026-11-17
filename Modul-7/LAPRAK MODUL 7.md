# <h1 align="center">Laporan Praktikum Modul 7 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Laluna Afril Diasyifa - 109082500009</p>

## Dasar Teori
Stack atau tumpukan merupakan salah satu jenis struktur data linier yang bekerja menggunakan prinsip LIFO (Last In, First Out), artinya data yang terakhir kali masuk ke dalam tumpukan akan menjadi data pertama yang keluar saat diambil [1]. Berbeda dengan linked list biasa yang memungkinkan penambahan atau penghapusan elemen di berbagai posisi, seluruh akses data pada stack hanya bisa dilakukan melalui satu pintu di bagian paling atas yang disebut TOP [1, 3]. Dalam pemrograman, konsep stack sering digunakan untuk menangani proses penyimpanan sementara, seperti pemanggilan fungsi rekursif, fitur undo/redo pada aplikasi, hingga perhitungan ekspresi matematika [1, 2].

### A. Implementasi Stack dengan Representasi Pointer<br/>
Pada representasi pointer, stack dibangun menyerupai Singly Linked List di mana setiap elemen berupa node (simpul) yang saling terhubung melalui alamat memori [1, 3]. Keunggulan dari pendekatan ini adalah ukuran tumpukan yang bersifat dinamis, sehingga kapasitas stack dapat terus bertambah selama memori masih tersedia tanpa perlu menentukan batas maksimal di awal [1].
#### 1. Komponen Utama dan Primitif
Komponen dasar pada stack berbasis pointer terdiri dari struktur node (elmStack) yang menyimpan nilai data (info) dan penunjuk ke elemen di bawahnya (next), serta penunjuk utama Top yang selalu mengarah pada elemen paling atas (bernilai Nil jika tumpukan kosong) [3]. Pengoperasiannya didukung oleh fungsi primitif seperti createStack() untuk membuat tumpukan kosong, isEmpty() untuk mengecek apakah tumpukan kosong, serta alokasi() dan dealokasi() untuk mengatur penggunaan memori secara dinamis [3].
#### 2. Operasi Push
Operasi Push digunakan untuk menambahkan elemen baru ke posisi paling atas tumpukan, yang cara kerjanya sama dengan operasi insert first pada linked list [3]. Langkahnya dimulai dengan membuat node baru P menggunakan fungsi alokasi(X), lalu mengarahkan P->next ke alamat yang sedang ditunjuk S.Top, dan terakhir memindahkan posisi S.Top agar menunjuk ke node baru P [3].
#### 3. Operasi Pop
Operasi Pop berfungsi untuk mengambil sekaligus menghapus elemen teratas dari tumpukan, mirip seperti operasi delete first pada linked list [3]. Proses ini dilakukan dengan menyimpan alamat S.Top ke dalam variabel bantu P, menggeser S.Top ke elemen berikutnya (S.Top = (S.Top)->next), memutuskan hubungan P->next menjadi Nil, dan mengembalikan simpul P agar datanya bisa diolah atau dihapus dari memori [3].

### B. Implementasi Stack dengan Representasi Tabel (Array)<br/>
Pada representasi tabel, struktur data stack diimplementasikan menggunakan array berindeks dengan jumlah kapasitas maksimal yang sudah ditentukan sejak awal (Imax) [1, 3]. Meskipun kapasitasnya terbatas dan statis, penggunaan array membuat proses pengaksesan data menjadi lebih cepat serta lebih hemat memori karena tidak membutuhkan ruang tambahan untuk menyimpan alamat pointer [1].
#### 1. Struktur Data dan Primitif
Struktur stack berbasis tabel tersusun atas array info berkapasitas tetap untuk menampung kumpulan data dan variabel integer Top sebagai penanda indeks elemen teratas (bernilai 0 saat stack dalam kondisi kosong) [3]. Karena ruang memori array sudah dipesan secara statis di awal program, fungsi primitif pada representasi ini tidak memerlukan alokasi() maupun dealokasi(), melainkan cukup memakai createStack(), isEmpty(), fungsi pencarian, serta prosedur viewStack() untuk menampilkan isi tumpukan [3].
#### 2. Operasi push
Dalam representasi tabel, penyisipan data baru melalui operasi Push dilakukan dengan menggeser posisi indeks Top naik satu tingkat (Top = Top + 1) selama tumpukan belum mencapai batas maksimum Imax [3]. Setelah indeks Top berpindah ke ruang kosong berikutnya, data baru X langsung dimasukkan ke dalam array pada indeks Top tersebut [3].
#### 3. Operasi pop
Pengambilan elemen teratas melalui operasi Pop dilakukan dengan menyalin nilai data yang berada di indeks Top ke dalam variabel penampung sementara (Temp = S.info[Top]) [3]. Setelah datanya diambil, nilai indeks Top dikurangi satu tingkat (Top = Top - 1) sehingga posisi puncak tumpukan mundur ke elemen sebelumnya tanpa perlu menghapus nilai lama pada indeks tersebut secara fisik [3].

## Guided 

### 1. stack.h

```C++
/* file : stack.h
   contoh ADT stack dengan representasi tabel */
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    char nim[20];
    char nama[20];
};
struct Stack {
    infotype info[10];
    int Top;
};

/* prototype */
/********* pengecekan apakah Stack kosong *********/
int isEmpty(Stack S);
/* mengembalikan nilai 0 jika stack kosong */
/********* pembuatan Stack *********/
void createStack(Stack &S);
/* I.S. sembarang
   F.S. terbentuk stack dengan Top=0 */
/********* penambahan elemen pada Stack *********/
void push(Stack &S, infotype X);
/* I.S. Stack mungkin kosong
   F.S. menambahkan elemen pada stack dengan nilai X, TOP=TOP+1 */
/********* penghapusan elemen pada list *********/
void pop(Stack &S, infotype &X);
/* I.S. stack tidak kosong
   F.S. nilai info pada indeks TOP disimpan pada X, kemudian TOP=TOP-1 */
/********* proses semua elemen list **********/
void viewStack(Stack S);
/* I.S. stack mungkin kosong
   F.S. jika stack tidak kosong menampilkan semua info yang ada pada stack
*/
#endif // STACK_H_INCLUDED
```

### 2. stack.cpp

```C++
#include "stack.h"

int isEmpty(Stack S) {
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;
    } else {
        cout << "Stack penuh, data tidak bisa ditemukan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi stack (dari TOP): " << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - "
                << S.info[i - 1].nama << endl;
        }
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "103112400001");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "103112400002");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "103112400003");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewStack(S);

    return 0;
}
```
penjelasan singkat guided 3

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:  
```
Type infotype : integer 
Type Stack < 
    info : array [20] of integer 
    top : integer 
>
procedure CreateStack( input/output S : Stack ) 
procedure push(input/output S : Stack,
    input x : infotype)
function pop(input/output t S : Stack )
      → infotype 
procedure printInfo( input S : Stack )
procedure balikStack(input/output S : 
    Stack )
```
### Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp” 
```
int main() 
{  
    cout << "Hello world!" << endl;  
    Stack S;  
    createStack(S);  
    Push(S,3);  
    Push(S,4);  
    Push(S,8);  
    pop(S)  
    Push(S,2);  
    Push(S,3);  
    pop(S);  
    Push(S,9);  
    printInfo(S);  
    cout<<"balik stack"<<endl;  
    balikStack(S);  
    printInfo(S);  
    return 0; 
} 
``` 

### 1. stack.h

```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    S.info[S.top] = x;
    S.top = S.top + 1;
}

infotype pop(Stack &S) {
    S.top = S.top - 1;
    return S.info[S.top];
}

void printInfo(Stack S) {
    if (S.top == 0) {
        cout << "Stack kosong" << endl;
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;
    while (kiri < kanan) {
        infotype temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri = kiri + 1;
        kanan = kanan - 1;
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
```
int main() 
{  
    cout << "Hello world!" << endl;  
    Stack S;  
    createStack(S);  
    pushAscending(S,3); 
    pushAscending(S,4); 
    pushAscending(S,8); 
    pushAscending(S,2); 
    pushAscending(S,3); 
    pushAscending(S,9); 
    printInfo(S); 
    cout<<"balik stack"<<endl; 
    balikStack(S); 
    printInfo(S); 
    return 0; 
}  
``` 

### 1. stack.h

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif
```

### 2. stack.cpp

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
        return -1;
    }
    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int awal = 0;
    int akhir = S.top;
    while (awal < akhir) {
        infotype temp = S.info[awal];
        S.info[awal] = S.info[akhir];
        S.info[akhir] = temp;
        awal++;
        akhir--;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (S.top >= 19) {
        cout << "Stack penuh!" << endl;
        return;
    }

    int i = S.top;
    while (i >= 0 && S.info[i] > x) {
        S.info[i + 1] = S.info[i];
        i--;
    }

    S.info[i + 1] = x;
    S.top++;
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.
```
int main() 
{ 
    cout << "Hello world!" << endl; 
    Stack S; 
    createStack(S); 
    getInputStream(S); 
    printInfo(S); 
    cout<<"balik stack"<<endl; 
    balikStack(S); 
    printInfo(S); 
    return 0; 
} 
```

### 1. stack.h

```C++
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif
```

### 2. stack.cpp

```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    S.info[S.top] = x;
    S.top = S.top + 1;
}

infotype pop(Stack &S) {
    S.top = S.top - 1;
    return S.info[S.top];
}

void printInfo(Stack S) {
    if (S.top == 0) {
        cout << "Stack kosong" << endl;
        return;
    }
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;
    while (kiri < kanan) {
        infotype temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;
        kiri = kiri + 1;
        kanan = kanan - 1;
    }
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
    }
}
```

### 3. main.cpp

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
