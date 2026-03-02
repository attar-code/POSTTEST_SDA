#include<iostream>
using namespace std;

void tukar(int* a, int* b){
    int sementara = *a;
    *a = *b;
    *b = sementara;
}

int main(){
    int first, second;
    cout << "masukkan angka pertama : ";
    cin >> first;
    cout << "masukkan angka kedua : ";
    cin >> second;

    cout << endl << "ANGKA SEBELUM DITUKAR" << endl;
    cout << "angka pertama : " << first << " | alamat pertama : " << &first << endl;
    cout << "angka kedua : " << second << " | alamat kedua : " << &second << endl;
    
    tukar(&first, &second);
    cout << endl << "ANGKA SETELAH DITUKAR" << endl;
    cout << "angka pertama : " << first << " | alamat pertama : " << &first << endl;
    cout << "angka kedua : " << second << " | alamat kedua : " << &second << endl;
}
