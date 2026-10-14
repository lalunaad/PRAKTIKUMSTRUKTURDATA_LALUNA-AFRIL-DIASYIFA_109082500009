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