# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Laluna Afril Diasyifa - 109082500009</p>

## Dasar Teori
Abstract Data Type (ADT) adalah model data yang didefinisikan oleh sekumpulan nilai (type) dan operasi terhadap nilai tersebut, tanpa mengharuskan pengguna mengetahui cara representasi dan implementasinya [1]. Prinsip ini sejalan dengan information hiding, yaitu detail rancangan disembunyikan di dalam modul agar bagian program lain tidak bergantung padanya [2].

### A. Konsep Abstract Data Type (ADT)<br/>
ADT terdiri dari TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. ADT yang lengkap juga memuat invarian dan aksioma, dan bersifat statik (berupa definisi) [1]. Di C/C++, TYPE diterjemahkan menjadi struct, sedangkan PRIMITIF menjadi fungsi atau prosedur.

#### 1. Type
Type dapat memuat ADT lain, misalnya garis yang terdiri dari dua ADT POINT [3].
#### 2. Primitif
Primitif adalah operasi dasar pada type, dan operasi terhadap objek hanya dilakukan melalui primitif tersebut [1][3].

### B. Primitif ADT<br/>
Primitif adalah operasi dasar pada type. Secara umum primitif dikelompokkan menjadi konstruktor, selector, mutator, dan operasi lain yang dibutuhkan type tersebut [1][3].
#### 1. Konstruktor dan Selector
Konstruktor membentuk nilai type, misalnya create_pelajaran(). Selector mengakses nilai komponen tanpa mengubahnya, biasanya berawalan Get [3].
#### 2.Mutator, Validator, dan Destruktor
Mutator mengubah nilai komponen (biasanya berawalan Set). Validator menguji apakah nilai dapat membentuk type sesuai batasan. Destruktor menghapus objek beserta memorinya.
#### 3. Baca/Tulis, Relasional, Aritmatika, dan Konversi
Operasi ini berturut-turut berfungsi sebagai antarmuka input/output, pembanding nilai, operasi hitung pada type buatan, dan pengubah type ke tipe dasar atau sebaliknya.

### C. Implementasi ADT dalam C++<br/>
Antarmuka dipisahkan dari realisasinya agar implementasi dapat berubah tanpa memengaruhi program pengguna [2].
#### 1. File Header (.h)
Berisi spesifikasi type dan primitif, dilindungi include guard (#ifndef, #define, #endif).
#### 2. File Body (.cpp)
Berisi realisasi primitif, sedapat mungkin memanfaatkan selector dan konstruktor.
#### 3. File Driver (main.cpp)
Berisi program utama yang memakai ADT melalui primitifnya.

## Guided 
Pada guided dibuat ADT `mahasiswa` yang terdiri dari tiga file, yaitu `mahasiswa.h`, `mahasiswa.cpp`, dan `main.cpp`.

### 1. mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
    
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif // MAHASISWA_H_INCLUDED

```
File mahasiswa.h berisi definisi tipe mahasiswa untuk menyimpan NIM beserta dua nilai, serta deklarasi fungsi inputMhs dan rata2. Selain itu, terdapat header guard untuk mencegah terjadinya pemanggilan ganda pada file header ini.

### 2. mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs (mahasiswa &m){
    cout << "input nim: ";
    cin >> m.nim;
    cout << "input nilai: ";
    cin >> m.nilai1;
    cout << "input nilai 2: ";
    cin >> m.nilai2;
}

float rata2 (mahasiswa m){
    return float(m.nilai1+m.nilai2)/2;
}


```
File mahasiswa.cpp berisi implementasi dari fungsi dan prosedur yang telah dideklarasikan sebelumnya. Prosedur inputMhs menggunakan parameter referensi (&m) supaya perubahan data langsung memperbarui variabel aslinya, sementara fungsi rata2 bertugas mengkalkulasi nilai rata-rata dari kedua nilai mahasiswa.

### 3. main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs (mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```
File `main.cpp` berfungsi sebagai program utama (*driver*) yang mendeklarasikan variabel bertipe `mahasiswa`, menjalankan prosedur `inputMhs` untuk mengoperasikan pengisian data, kemudian memanggil fungsi `rata2` untuk menampilkan hasil perhitungannya ke layar.

## Unguided 

### 1. Program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.
### 1. mahasiswa.h

```C++
#ifndef Mahasiswa_H_Included
#define Mahasiswa_H_Included

using namespace std;

struct mahasiswa {
    string nama;
    char nim[13];
    int nilaiUTS, nilaiUAS, nilaiTugas;
     float nilaiAkhir;
};

void inputMhs (mahasiswa &m);
float nilaiAkhir (mahasiswa m);
void hasil (mahasiswa m);
#endif
```
### 2. mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input Nama = ";
    cin >> (m).nama;
    cout << "Input NIM = ";
    cin >> (m).nim;
    cout << "Input Nilai UTS = ";
    cin >> (m).nilaiUTS;
    cout << "Input Nilai UAS = ";
    cin >> (m).nilaiUAS;
    cout << "Input Nilai Tugas = ";
    cin >> (m).nilaiTugas;
}

float nilaiAkhir(mahasiswa m) {
    return float(0.3 * m.nilaiUTS + 0.4 * m.nilaiUAS + 0.3 * m.nilaiTugas);
}

void hasil(mahasiswa m) {
    cout << "Nama        :" << m.nama << endl;
    cout << "NIM         :" << m.nama << endl;
    cout << "Nilai UTS   :" << m.nama << endl;
    cout << "Nilai UAS   :" << m.nama << endl;
    cout << "Nilai Tugas :" << m.nama << endl;
    m.nilaiAkhir = nilaiAkhir(m);
}
```
### 3. main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main(){
    mahasiswa mhs[10];
    int n;
    
    cout << "Masukan Jumlah Mahasiswa (1-10): ";
    cin >> n;
  
    if (n < 1 || n > 10) {
        cout << "Masukan harus antara 1-10." << endl;
    } else {

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa " << i + 1 << endl;
    
        inputMhs(mhs[i]);
    }
    
    cout << "\n-----Data Semua Mahasiswa-----" << endl;
    
    for (int i =  0; i < n; i++){
        cout << "Nama        :" << mhs[i].nama << endl;
        cout << "NIM         :" << mhs[i].nim << endl;
        cout << "Nilai UTS   :" << mhs[i].nilaiUTS << endl;
        cout << "Nilai UAS   :" << mhs[i].nilaiUAS << endl;
        cout << "Nilai Tugas :" << mhs[i].nilaiTugas << endl;
        cout << "Nilai Akhir : " << nilaiAkhir (mhs[i]) << endl;
        
        cout <<"========================" << endl;
    }
    
}
    return 0;

}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-3/Output-Modul3/output-unguided1.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-3/Output-Modul3/output-unguided1(2).png?raw=true)
Program ini menerapkan konsep ADT (Abstract Data Type) terpisah yang terbagi menjadi tiga file (`mahasiswa.h`, `mahasiswa.cpp`, dan `main.cpp`) untuk mengolah data mahasiswa secara terstruktur. File `mahasiswa.h` berfungsi menyimpan definisi `struct mahasiswa` dan deklarasi fungsi yang dilindungi oleh *include guard*. Realisasi fungsinya terdapat pada `mahasiswa.cpp`, yang memuat prosedur `inputMhs` dengan parameter referensi (`&m`) untuk pengisian data serta fungsi `nilaiAkhir` untuk menghitung nilai akhir sesuai bobot persentase. Selanjutnya, `main.cpp` bertindak sebagai program utama yang menyimpan data ke dalam *array of struct* berkapasitas maksimal 10 elemen, melakukan validasi jumlah input, dan menampilkan seluruh informasi mahasiswa beserta nilai akhirnya ke layar.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:
### 1. pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>

using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
### 2. pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
### 3. main.cpp
```C++
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-3/Output-Modul3/output-unguided2.png?raw=true)

Program ini menerapkan Abstract Data Type (ADT) terpisah yang terbagi menjadi file `pelajaran.h`, `pelajaran.cpp`, dan `main.cpp` untuk mengelola data mata pelajaran secara modular. File `pelajaran.h` berfungsi menyimpan definisi `struct pelajaran` beserta deklarasi fungsi yang dilindungi oleh *header guard*. Implementasi kodenya berada pada `pelajaran.cpp`, yang memuat fungsi `create_pelajaran` untuk menginisialisasi atribut `namaMapel` dan `kodeMapel`, serta prosedur `tampil_pelajaran` untuk mencetak nilainya. Selanjutnya, file `main.cpp` bertindak sebagai program utama yang menyiapkan data string awal, memanggil fungsi pembentuk objek, dan menampilkan hasilnya ke layar.

### 3. ### 3. Buatlah program dengan ketentuan :
### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
### - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

### 1. array.h
```C++
#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED

void tampilArray (int a[3][3]) ;

void tukarArray (int a[3][3], int b[3][3], int baris, int kolom) ;

void tukarPointer (int *p1, int *p2) ;

#endif 
```
### 2. array.cpp
```C++
#include <iostream>
#include "array.h"
using namespace std;

void tampilArray(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```
### 3. main.cpp
```C++
#include <iostream>
#include "array.h"
using namespace std;

int main()
{
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,0,4},{3,2,1}};
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;
    int baris, kolom;

    cout << "array A" << endl;
    tampilArray (A) ;
    cout << "array B" << endl;
    tampilArray (B) ;

    cout << "tukar posisi (baris kolom, 0-2) = ";
    cin >> baris >> kolom;
    if (baris >= 0 && baris <= 2 && kolom >= 0 && kolom <= 2) {
        tukarArray (A, B, baris, kolom) ;
        cout << "setelah ditukar" << endl;
        cout << "array A" << endl;
        tampilArray (A) ;
        cout << "array B" << endl;
        tampilArray (B) ;
    } else {
        cout << "posisi tidak valid" << endl;
    }

    cout << "sebelum tukar pointer : x = " << *p1 << ", y = " << *p2 << endl;
    tukarPointer (p1, p2) ;
    cout << "sesudah tukar pointer : x = " << *p1 << ", y = " << *p2 << endl;
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-3/Output-Modul3/output-unguided3.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-3/Output-Modul3/output-unguided3(2).png?raw=true)


Program ini menerapkan struktur modular berbasis ADT terpisah (array.h, array.cpp, dan main.cpp) untuk mengolah matriks $3 \times 3$ serta pointer. File array.h memuat deklarasi fungsi dengan perlindungan header guard, sementara array.cpp berisi implementasinya, yaitu prosedur tampilArray untuk mencetak elemen matriks, tukarArray untuk menukar nilai pada posisi matriks yang dipilih, dan tukarPointer untuk menukar nilai dua variabel langsung lewat alamat memorinya. File main.cpp sendiri berperan sebagai driver utama yang menyiapkan matriks dan pointer, menerima input indeks baris serta kolom dari pengguna, lalu menjalankan seluruh proses penukaran data tersebut.

## Kesimpulan
Praktikum ini menerapkan konsep Abstract Data Type (ADT) dan pemrograman modular berbasis struktur multi-file (.h, .cpp, dan main.cpp) untuk membangun program C++ yang terorganisasi dan mudah dipelihara. Pada nomor 1, penggunaan array of struct dan parameter referensi (&) berhasil diterapkan untuk memproses pengisian data serta perhitungan nilai akhir mahasiswa. Nomor 2 menunjukkan pengkapsulan data mata pelajaran melalui tipe data terstruktur dan fungsi pembentuk objek (create_pelajaran). Terakhir, nomor 3 membuktikan penerapan operasi manipulasi array dua dimensi ($3 \times 3$) serta penggunaan pointer untuk melakukan pertukaran nilai langsung pada alamat memori. Secara keseluruhan, pemisahan antarmuka dan implementasi program memudahkan proses pemeliharaan kode serta mencegah error redefinisi melalui penggunaan header guard.

## Referensi
[1] Modul Praktikum Struktur Data, Modul 3 Abstract Data Type (ADT). Fakultas Informatika, Telkom University.