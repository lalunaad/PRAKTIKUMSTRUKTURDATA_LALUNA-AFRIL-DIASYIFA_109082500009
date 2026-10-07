# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Laluna Afril Diasyifa - 109082500009</p>

## Dasar Teori
Bahasa C++ memiliki berbagai konsep dasar yang digunakan dalam pengolahan data dan pembuatan program. Pada materi ini dibahas beberapa konsep penting, yaitu array, pointer, fungsi, prosedur, serta parameter fungsi. Konsep tersebut digunakan untuk membuat program yang lebih terstruktur serta mempermudah proses penyimpanan dan pengolahan data.

### A. Array<br/>
...
#### 1. Array Satu Dimensi
Array merupakan kumpulan data yang memiliki nama yang sama dan setiap elemennya memiliki tipe data yang sama. Setiap elemen pada array dapat diakses menggunakan indeks. Dalam bahasa C++, penyimpanan elemen array berada pada lokasi memori yang berurutan dan indeks elemen dimulai dari 0
#### 2. Array Dua Dimensi
Array satu dimensi merupakan array yang hanya memiliki satu larik data. Array ini dapat digunakan untuk menyimpan sekumpulan data dengan tipe yang sama. Bentuk deklarasi array satu dimensi adalah tipe_data nama_var[ukuran]. Sebagai contoh, int nilai[10] digunakan untuk membuat array bernama nilai yang memiliki 10 elemen bertipe integer
#### 3. Array Berdimensi Banyak
Array berdimensi banyak merupakan array yang memiliki lebih dari dua indeks. Jumlah indeks yang digunakan menunjukkan jumlah dimensi array. Bentuk deklarasinya dapat menggunakan beberapa ukuran, seperti int data_rumit[4][6][6] untuk array tiga dimensi [1].

### B. Pointer<br/>
Pointer merupakan variabel yang digunakan untuk menyimpan alamat memori dari variabel lain. Pointer memungkinkan program untuk mengakses nilai dari variabel berdasarkan alamat memori yang ditunjuk. Pointer dideklarasikan menggunakan tanda *, sedangkan tanda & digunakan untuk mendapatkan alamat memori suatu variabel [1].
...
#### 1. Data dan Memori
Data yang digunakan oleh program disimpan di dalam memori komputer. Setiap lokasi memori memiliki alamat yang digunakan sebagai identitas. Ketika sebuah variabel dibuat, sistem operasi akan mengalokasikan ruang memori untuk menyimpan variabel tersebut. Alamat memori suatu variabel dapat diketahui dengan menggunakan operator & [1].
#### 2. Pointer dan Alamat
Pointer digunakan untuk menyimpan alamat dari variabel lain. Sebagai contoh, int *p_int merupakan pointer yang digunakan untuk menunjuk data bertipe integer. Jika p_int = &j, maka pointer p_int menyimpan alamat dari variabel j. Nilai dari variabel yang ditunjuk dapat diakses menggunakan operator * pada pointer [1].
#### 3. Pointer dan Array
Pointer memiliki hubungan yang erat dengan array karena alamat elemen array dapat disimpan dalam pointer. Jika sebuah pointer menunjuk ke elemen pertama array, penambahan nilai pada pointer dapat digunakan untuk mengakses elemen berikutnya. Misalnya, jika pa menunjuk ke a[0], maka *(pa+1) dapat digunakan untuk mengakses nilai a[1].
#### 4. Pointer dan String
String pada C++ dapat direpresentasikan sebagai kumpulan karakter atau array karakter. String yang menggunakan array karakter diakhiri dengan karakter null \0. String dapat diakses berdasarkan indeks seperti halnya array. Selain menggunakan array, string juga dapat digunakan bersama pointer karakter untuk menunjuk ke karakter dalam string [1].

### C. Fungsi<br/>
Fungsi merupakan blok kode yang dibuat untuk melaksanakan tugas tertentu. Penggunaan fungsi membuat program menjadi lebih terstruktur karena program dapat dibagi menjadi beberapa bagian yang lebih kecil. Fungsi juga dapat mengurangi pengulangan kode sehingga kode program menjadi lebih efisien [1].
...
#### 1. Struktur Fungsi
Fungsi pada C++ memiliki tipe nilai balik, nama fungsi, parameter, dan blok pernyataan. Bentuk umum fungsi adalah tipe_keluaran nama_fungsi(daftar_parameter). Fungsi dapat menerima data melalui parameter dan menghasilkan nilai balik yang dapat digunakan oleh program [1].
#### 2.Parameter Fungsi
Parameter digunakan sebagai masukan yang diberikan kepada fungsi untuk kemudian diproses. Parameter pada fungsi terdiri dari parameter formal dan parameter aktual. Parameter formal merupakan variabel yang terdapat pada saat fungsi didefinisikan, sedangkan parameter aktual merupakan nilai atau variabel yang diberikan ketika fungsi dipanggil [1].

### D. Prosedur<br/>
Prosedur merupakan fungsi yang tidak mengembalikan nilai. Dalam C++, prosedur umumnya dibuat menggunakan fungsi dengan tipe void. Prosedur digunakan untuk menjalankan tugas tertentu tanpa menghasilkan nilai balik yang dikembalikan kepada pemanggil [1].
...
#### 1. Fungsi Void
Fungsi void digunakan ketika suatu fungsi hanya perlu menjalankan suatu proses tanpa mengembalikan nilai. Bentuk umumnya adalah void nama_prosedur(daftar_parameter) kemudian diikuti oleh blok pernyataan yang akan dijalankan [1].
#### 2. Penggunaan Prosedur
Prosedur dapat digunakan untuk memisahkan suatu proses tertentu dari program utama. Dengan demikian, program menjadi lebih terstruktur dan setiap proses dapat dibuat dalam bagian yang berbeda sehingga lebih mudah dipahami dan dikembangkan.

### E. Cara Melewatkan Parameter<br/>
Parameter dapat diberikan kepada fungsi dengan beberapa cara. Pada modul ini dibahas tiga cara melewatkan parameter, yaitu pemanggilan dengan nilai atau call by value, pemanggilan dengan pointer atau call by pointer, dan pemanggilan dengan referensi atau call by reference [1].
...
#### 1. Call by Value
Call by value merupakan cara melewatkan parameter dengan menyalin nilai dari parameter aktual ke parameter formal. Perubahan yang terjadi pada parameter formal tidak akan mengubah nilai parameter aktual yang berada di luar fungsi [1].
#### 2. Call by Pointer
Call by pointer merupakan cara melewatkan alamat suatu variabel ke dalam fungsi. Parameter fungsi menggunakan pointer sehingga fungsi dapat mengakses dan mengubah nilai variabel yang berada di luar fungsi. Pada pemanggilannya, alamat variabel diberikan menggunakan operator & [1].
#### 3. Call by Reference
Call by reference merupakan cara melewatkan alamat variabel ke dalam fungsi menggunakan referensi. Dengan cara ini, perubahan terhadap parameter di dalam fungsi dapat memengaruhi variabel yang digunakan saat fungsi dipanggil. Berbeda dengan call by pointer, pemanggilan fungsi tidak perlu menggunakan operator & pada argumen [1].

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[5];

    nilai[0]= 80;
    nilai[1]= 75;
    nilai[2]= 90;
    nilai[3]= 85;
    nilai[4]= 95;

    for (int i = 0;i<5;i++) {
        cout<<"Nilai ke-"<< i+1<<" = "<<nilai[i]<<endl;
    }

    return 0;
}
```
Program tersebut digunakan untuk menyimpan dan menampilkan 5 nilai menggunakan array satu dimensi. Array nilai[5] menyimpan lima data bertipe integer, kemudian setiap elemennya diisi dengan nilai 80, 75, 90, 85, dan 95. Perulangan for digunakan untuk mengakses setiap elemen array dari indeks 0 sampai 4 dan menampilkan nilai tersebut ke layar menggunakan cout.

### 2. Array 2 Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[3][3] = {
        {80,75,90},
        {85,90,88},
        {70,80,85}
    };
        // Print array 2 dimensi
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout << nilai [i][j]<<" ";
        }

        cout << endl;
    }
    cout<<endl;
    cout<<nilai[1][2]<<endl; // menghasilkan baris ke 1, kolom ke 2 = 88 (ingat baris dan kolom dimulai dari 0)
    return 0;
}
```
Program tersebut digunakan untuk membuat dan menampilkan array dua dimensi berukuran 3×3 yang berisi data nilai. Perulangan for bersarang digunakan untuk mengakses setiap baris dan kolom pada array, kemudian menampilkannya dalam bentuk tabel. Selain itu, nilai[1][2] digunakan untuk mengakses elemen pada baris ke-2 dan kolom ke-3 karena indeks array dimulai dari 0, sehingga menghasilkan nilai 88.

### 3. Array 3 Dimensi

```C++
#include <iostream>
using namespace std;

int main(){

    int data[2][2][3] = {
        {
            {10,20,30},
            {40,50,60}
        },
        {
            {70,80,90},
            {100,110,120}
        }
    };

    cout<< data[0][1][2]<<endl;

    return 0;
}
```
Program tersebut digunakan untuk membuat dan menginisialisasi array tiga dimensi berukuran 2×2×3 yang berisi data integer. Program kemudian mengakses elemen spesifik menggunakan indeks `data[0][1][2]`. Indeks `[0]` merujuk pada blok array dua dimensi pertama, indeks `[1]` merujuk pada baris ke-2, dan indeks `[2]` merujuk pada kolom ke-3 (karena indeks array dimulai dari 0), sehingga menghasilkan nilai keluaran 60.

### 4. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
   int temp_max = a;

   if (b > temp_max) {
      temp_max = b;
   }
   if (c > temp_max) {
      temp_max = c;
   }
   return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1: ";
    cin >> x;

    cout << "Masukkan nilai 2: ";
    cin >> y;

    cout << "Masukkan nilai 3: ";
    cin >> z;

    cout << "Nilai maksimum = "
         << maks3(x, y, z);

    return 0;
}
```
Program tersebut digunakan untuk mencari dan menampilkan nilai maksimum dari tiga bilangan bulat yang diinputkan pengguna. Fungsi maks3 digunakan untuk membandingkan ketiga nilai tersebut menggunakan percabangan if untuk menentukan angka terbesar. Selain itu, program menerima masukan x, y, dan z pada fungsi main, kemudian memanggil fungsi maks3 untuk memprosesnya, sehingga menghasilkan nilai maksimum dari ketiga inputan tersebut.

### 5. Procedure

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Praktikum Struktur Data" << endl;
}

int main() {
    sapa();
    return 0;
}
```
Program tersebut digunakan untuk menampilkan pesan sambutan ke layar menggunakan fungsi tanpa nilai kembalian (void). Fungsi `sapa` digunakan untuk mencetak teks "Selamat datang di Praktikum Struktur Data". Selain itu, fungsi `main` bertugas memanggil fungsi `sapa()` agar pesan tersebut dapat dieksekusi dan ditampilkan.

### 6. Pointer 1

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    cout<<"Nilai variabel angka: "<< angka << endl;
    cout<<"Alamat variabel angka: "<< &angka << endl;

    return 0;
}
```
Program tersebut digunakan untuk menampilkan nilai dan alamat memori dari sebuah variabel integer. Variabel `angka` diinisialisasi dengan nilai 100, kemudian program mencetak nilai tersebut ke layar. Selain itu, program menggunakan operator address-of (`&`) pada `&angka` untuk mengakses dan menampilkan alamat memori tempat variabel tersebut disimpan, sehingga menunjukkan perbedaan antara nilai data dan lokasi memorinya.

### 7. Pointer 2

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka        :" << angka << endl;
    cout << "Alamat angka       :" << &angka << endl;
    cout << "Isi pointer        :" << pointer << endl;
    cout << "Nilai dari pointer :" << *pointer << endl;

    return 0; 
}
```
Program tersebut digunakan untuk mendemonstrasikan konsep pointer. Variabel `angka` bernilai 100 dan alamat memorinya disimpan ke dalam `pointer` menggunakan operator `&`. Selain itu, program menampilkan nilai variabel, alamat memori, dan nilai yang ditunjuk pointer menggunakan operator `*`, sehingga menunjukkan hubungan antara data dan lokasi memorinya.

### 8. Pointer Array

```C++
#include <iostream>
using namespace std;

int main(){
    char arr[6];

    arr[0]='a';
    arr[1]='b';
    arr[2]='c';
    arr[3]='b';
    arr[4]='d';
    arr[5]='e';

    cout<< arr[3]<<endl; //menampilkan value
    cout<< &(arr[4])<<endl; //menampilkan alamat value
}
```
Program tersebut digunakan untuk mengakses nilai dan alamat memori pada array karakter. Array `arr` diisi dengan enam karakter, kemudian program menampilkan nilai pada indeks ke-3 dan alamat memori elemen indeks ke-4 menggunakan operator `&`, sehingga menunjukkan cara mengambil data spesifik serta lokasi penyimpanannya dalam memori.

### 8. Call By Pointer, Reference, Value

```C++
#include <iostream>
using namespace std;

//BY POINTER
void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


// BY REFERENCE
// #include <iostream>
// using namespace std;

// void tukar(int &x, int &y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     tukar(a, b); 

//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }

//BY VALUE
// #include <iostream>
// using namespace std;

// void tukar(int x, int y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     // Memanggil fungsi dengan mengirimkan nilainya saja
//     tukar(a, b);

//     // Hasil print di bawah ini angkanya akan tetap a = 4 dan b = 6
//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }
```
Program tersebut digunakan untuk mendemonstrasikan penukaran nilai dua variabel menggunakan metode *pass by pointer*. Fungsi `tukar` menerima alamat memori variabel `a` dan `b`, kemudian menukar nilai aslinya di memori menggunakan operator dereference (`*`). Selain itu, program menampilkan nilai sebelum dan sesudah pemanggilan fungsi, sehingga membuktikan bahwa perubahan nilai terjadi secara langsung pada variabel asli di fungsi `main`.




## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3  

```C++
#include <iostream>
using namespace std;

int main(){
    int matriks1[3][3] = {

    };

    int matriks2[3][3] = {

    };

    cout<<"Masukan nilai Matriks 1"<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout<<"Masukan isi Matriks baris-"<<i+1<<" dan kolom-"<<j+1<<" : ";
            cin >> matriks1 [i][j];
        }
    }


    cout<<"Masukan nilai Matriks 2"<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout<<"Masukan isi Matriks baris-"<<i+1<<" dan kolom-"<<j+1<<" : ";
            cin >> matriks2 [i][j];
        }
    }


    cout<<"=== Hasil Matriks 1 ==="<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout << matriks1 [i][j]<<" ";
        }
        cout << endl;
    }

    cout<<"=== Hasil Matriks 2 ==="<<endl;
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout << matriks2 [i][j]<<" ";
        }
        cout << endl;
    }

    cout<<endl;

    cout << "=== Operasi matriks ===" << endl;
    
    cout << "Penjumlahan matriks: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks1[i][j] + matriks2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPengurangan matriks: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks1[i][j] - matriks2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nPerkalian matriks: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int hasilKali = 0;
            for (int k = 0; k < 3; k++) {
                hasilKali += matriks1[i][k] * matriks2[k][j];
            }
            cout << hasilKali << " ";
        }
        cout << endl;
    }


}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-2/output/output-unguided1.jpeg?raw=true)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/lalunaad/PRAKTIKUMSTRUKTURDATA_LALUNA-AFRIL-DIASYIFA_109082500009/blob/main/Modul-2/output/output-unguided1(2).jpeg?raw=true)

Program tersebut digunakan untuk melakukan operasi penjumlahan, pengurangan, dan perkalian pada dua matriks berukuran 3x3 yang diinputkan oleh pengguna. Program menggunakan perulangan bersarang untuk menerima input, menampilkan isi matriks, serta menghitung hasil penjumlahan dan pengurangan secara elemen per elemen. Selain itu, program menghitung perkalian matriks dengan mengalikan elemen baris dan kolom menggunakan loop tambahan, sehingga menampilkan hasil lengkap dari ketiga operasi matematika tersebut ke layar.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel  
```C++
#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp;

    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp;

    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 4;
    int b = 6;
    int c = 8;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "\nSetelah ditukar Pointer: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    a = 4;
    b = 6;
    c = 8;

    tukarReference(a, b, c);

    cout << "\nSetelah ditukar Reference: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
