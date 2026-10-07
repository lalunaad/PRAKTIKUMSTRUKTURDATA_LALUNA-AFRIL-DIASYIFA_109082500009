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