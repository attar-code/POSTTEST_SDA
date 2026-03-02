#include <iostream>
using namespace std;

int FindMin(int angka[], int n, int &indexmin){
    int min = angka[0];
    indexmin = 0;
    
    for(int i = 1;i < n;i++){
        if(angka[i] < min) {
            min = angka[i];
            indexmin = i;
        }
    }
    return min;
}

int main(){
    int fibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = sizeof(fibonacci) / sizeof(fibonacci[0]);
    int indexmin;
    int minimum = FindMin(fibonacci, n, indexmin);
    cout << "nilai minimum : " << minimum << endl;
    cout << "index minimum : " << indexmin;
    return 0;
}

/*

Hitung Tmin dan Tmax secara manual    Tmin   Tmax
procedure FindMax                  C1   1      1
min ← A[0]                         C2   1      1
for i ← 1 to n - 1 do              C3   n      n
if A[i] < min then                 C4  n-1    n-1
min ← A[i]                         C5   0     n-1
end if                             C6  n-1    n-1 
end for                            C7   n      n
return min                         C8   1      1
end procedure                      C9   1      1

total :
Tmin = C1 + C2 + C3n + C4(n-1) + 0 + C6(n-1) + C7n + C8 + C9
     = C1 + C2 + C3n + C4n - C4 + C6n - C6 + C7n + C8 + C9  
     = (C3n + C4n + C6n + C7n) + (C1 + C2 - C4 - C6 + C8 + C9)
     = (1n+1n+1n+1n) + (1+1-1-1+1+1)
     = 4n+4 membentuk fungsi linear. karena fungsi linear maka
    Big-O => O(n)

Tmax = C1 + C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8 + C9
     = C1 + C2 + C3n + C4n - C4 + C5n - C5 + C6n - C6 + C7n + C8 + C9  
     = (C3n + C4n + C5n + C6n + C7n) + (C1 + C2 - C4 - C5 - C6 + C8 + C9)
     = (1n+1n+1n+1n+1n) + (1+1-1-1-1+1+1)
     =5n+3 sama-sama membentuk fungsi linear, maka Big-O => O(n)

penjelasan : 

algoritma ini cuman ngecek semua elemen array satu per satu
pertama ambil A[0] sebagai nilai awal minimum

best case:
jika tidak ada elemen yang lebih kecil dari A[0], maka kondisi if tidak pernah dijalankan
tapi perulangannya tetap jalan sampai n-1 kali
jadi tetap linear → O(n)

worst case:
jika setiap elemen lebih kecil dari sebelumnya, maka setiap iterasi akan update nilai minimum
meskipun ada tambahan assignment, jumlah perulangan tetap n-1 kali
Jadi tetap linear → O(n).

Karena best dan worst sama-sama linear, maka kompleksitas waktunya O(n)
*/