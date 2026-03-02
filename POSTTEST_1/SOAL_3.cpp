#include<iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* awal = arr;
    int* lanjut = arr + n - 1;

    while (awal < lanjut) {
        int temp = *awal;
        *awal = *lanjut;
        *lanjut = temp;

        awal++;
        lanjut--;
    }
}


int main(){
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = sizeof(prima) / sizeof(prima[0]);
    cout << "Sebelum dibalik" << endl;
    for(int i = 0; i < n; i++){
        cout << "Nilai : " << prima[i] << "   | alamat : " << &prima[i] << endl;
    }

    cout << endl;

    reverseArray(prima, n);
    cout << "Setelah dibalik" << endl;
    for(int i = 0; i < n; i++){
        cout << "Nilai : " << prima[i] << "   | alamat : " << &prima[i] << endl;
    }

}