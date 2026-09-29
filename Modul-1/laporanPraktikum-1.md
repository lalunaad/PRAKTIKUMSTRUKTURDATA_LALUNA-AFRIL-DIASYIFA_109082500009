# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Laluna Afril Diasyifa - 109082500009</p>

## Dasar Teori
Sebelum mempelajari struktur data, pemahaman mengenai lingkungan pengembangan (IDE) serta dasar-dasar bahasa pemrograman C++ sangat diperlukan. Modul ini membahas penggunaan Code Blocks IDE, konsep dasar bahasa C++, operasi input/output, operator, fungsi kondisional, perulangan, hingga tipe data struktur yang menjadi fondasi dalam pembuatan program.

### A. Pengenalan Code Blocks IDE
Code Blocks merupakan kakas (tool) free, open-source, dan cross-platform IDE yang berorientasi pada bahasa C, C++, dan Fortran.
#### 1. Instalasi Code Blocks dilakukan dengan mengunduh berkas pada situs resmi dan memilih installer yang menggunakan mingw-setup agar compiler terpasang secara otomatis.
#### 2. Cara Menggunakan Code Blocks dimulai dengan membuat project baru (Console Application), menuliskan syntax pada editor, serta membuat class atau file baru (C/C++ source atau header).
#### 3. Kompilasi dan Penanganan Error dilakukan menggunakan fitur Build (Ctrl+F9), Run (Ctrl+F10), atau Build and Run (F9). Jika terjadi kesalahan sintaks, panel error message akan mengindikasikan lokasi baris kode yang bermasalah, sedangkan fitur Clean dapat digunakan jika program gagal di-run.

### B. Dasar Pemrograman C++
Bahasa C++ diciptakan oleh Bjarne Stroustrup di AT&T Bell Laboratories pada awal 1980-an berbasis C ANSI dengan penambahan fasilitas kelas (C with class) dan pembeban lebihan operator.
#### 1. Variabel digunakan untuk menyimpan nilai yang bisa berubah-ubah saat program berjalan, sedangkan konstanta (ditambahkan kata kunci const di depannya) digunakan untuk menyimpan nilai yang tetap dan tidak dapat diubah.
#### 2. Identifier, Tipe Data, Variabel, dan Konstanta digunakan untuk mengelola data. Identifier wajib diawali huruf atau garis bawah (_), bersifat case sensitive, dan tidak boleh memuat spasi atau operator. Tipe data dasar meliputi char, int, long, float, dan double. Nilai variabel dapat berubah, sedangkan konstanta (const) bernilai tetap.
#### 3. Input dan Output menggunakan perintah cout dengan operator << untuk menampilkan data, serta cin dengan operator >> atau fungsi getchar() untuk menerima masukan karakter dari keyboard.

### C. Variabel, Konstanta, dan Input/Output
C++ menyediakan berbagai jenis operator dan struktur kontrol untuk manipulasi data serta pengaturan alur eksekusi program.
#### 1. Operator dan Pemodifikasi Tipe mencakup operator aritmatika, assignment, logika, unary, sizeof untuk menghitung ukuran memori dalam byte, serta increment (++) dan decrement (--) baik prefix maupun postfix. Tipe data juga dapat ditambah type modifier seperti unsigned, short, atau long.
#### 2. Kondisional (Percabangan) digunakan untuk pengambilan keputusan berdasarkan kondisi benar atau salah menggunakan pernyataan if, if-else (dapat disederhanakan dengan ekspresi kondisional ? :), dan switch-case.
#### 3. Perulangan dan Struktur mencakup perulangan menggunakan for, while, dan do while untuk pengefisienan eksekusi sub-program, serta tipe data bentukan struct untuk mengelompokkan beberapa variabel dengan tipe data berbeda ke dalam satu kesatuan nama.   

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.  

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian = " << a * b << endl;
    cout << "Pembagian = " << a / b << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-1/output/output-soal1.png?raw=true)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-1/output/output2-soal1.png?raw=true)

Program ini berfungsi untuk menghitung operasi aritmatika dari dua bilangan desimal. Setelah variabel a dan b dibuat dan diisi input dari user, program langsung menampilkan hasil penjumlahan, pengurangan, dan perkalian. Khusus untuk pembagian, ditambahkan pengecekan pakai if-else untuk memastikan nilai b tidak nol, tujuannya supaya program tidak error saat dijalankan.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100 


```C++
#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas", "dua belas", "tiga belas",
        "empat belas", "lima belas", "enam belas",
        "tujuh belas", "delapan belas", "sembilan belas"
    };

    if (angka < 20) {
        cout << satuan[angka];
    }
    else if (angka < 100) {
        cout << satuan[angka / 10] << " puluh";

        if (angka % 10 != 0) {
            cout << " " << satuan[angka % 10];
        }
    }
    else if (angka == 100) {
        cout << "seratus";
    }
    else {
        cout << "Angka tidak valid";
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-1/output/output-soal2.png?raw=true)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-1/output/output2-soal2.png?raw=true)

​Program ini mengubah angka 0–100 menjadi teks terbilang. Setelah memvalidasi batas input, program menangani angka khusus (0, 10, 100) secara langsung dan mengambil kata satuan (1–9) dari array. Untuk angka 11–19, program menambahkan kata "belas", sedangkan angka 20–99 dipecah menjadi nilai puluhan dan satuan menggunakan operator / dan % lalu digabungkan.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {

        for (int j = n; j > i; j--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int j = 0; j < n; j++) {
        cout << "  ";
    }
    cout << "*";

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-1/output/output-soal3.png?raw=true)


##### Output 2
![Screenshot Output Unguided 3_2](
https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-1/output/output2-soal3.png?raw=true)

​Program ini mencetak pola angka cermin berbasis input n dengan karakter bintang (*) di tengahnya. Melalui perulangan for bersarang, program mengatur spasi awal, lalu mencetak angka menurun dari (n - i) ke 1, tanda *, dan angka menaik kembali ke (n - i). Jumlah angka berkurang di setiap baris hingga baris terakhir hanya menyisakan tanda bintang.

## Kesimpulan
Praktikum Modul 1 memberikan pemahaman dasar mengenai penggunaan Code Blocks IDE dan bahasa pemrograman C++. Melalui praktikum ini, dapat dipahami cara membuat, mengompilasi, menjalankan, serta menangani kesalahan pada program C++. Selain itu, praktikum juga memperkenalkan penggunaan variabel, tipe data, input/output, operator, percabangan, dan perulangan. Penerapan konsep tersebut dilakukan melalui beberapa program, seperti operasi aritmatika dua bilangan, mengubah angka menjadi bentuk tulisan, serta membuat pola angka menggunakan perulangan bersarang. Dengan demikian, praktikum ini menjadi dasar untuk memahami pembuatan program C++ yang lebih kompleks pada materi selanjutnya.

## Referensi
[1] Tim Asisten Praktikum. (t.t.). Modul 1: Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama). Telkom University.
<br>[2] Indahyanti, Uce., & Rahmawati Yunianita. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Sidoarjo: Umsida Press.
Diakses melalui
https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...