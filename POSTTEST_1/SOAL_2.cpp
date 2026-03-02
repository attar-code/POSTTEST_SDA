#include<iostream>
using namespace std;

struct mahasiswa{
    string nama, nim;
    float ipk;
};

int main(){
    mahasiswa mhs[5];
    for(int i = 0; i < 5; i++){
        cout << "\nmahasiswa ke-" << i+1 << endl;
        cout << "input nama mahasiswa : ";
        getline(cin, mhs[i].nama);
        
        cout << "input nim mahasiswa  : ";
        cin >> mhs[i].nim;
        
        cout << "input ipk mahasiswa  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    for(int i = 0; i < 5; i++){
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "NAMA : " << mhs[i].nama << "\nNIM  : " << mhs[i].nim << "\nIPK  : " << mhs[i].ipk << endl;
    }
    int tertinggi = 0;
    for (int i = 0; i < 5; i++){
        if (mhs[i].ipk > mhs[tertinggi].ipk){
            tertinggi = i;
        }
    }
    cout << endl;
    cout << "Mahasiswa dengan IPK tertinggi" << endl;
    cout << "NAMA : " << mhs[tertinggi].nama << endl;
    cout << "NIM  : " << mhs[tertinggi].nim << endl;
    cout << "IPK  : " << mhs[tertinggi].ipk << endl;
    return 0;
}