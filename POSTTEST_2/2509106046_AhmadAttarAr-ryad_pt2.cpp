#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>

using namespace std;

struct JadwalKereta{
    string NamaKereta, Asal, Tujuan, JamKeberangkatan, JamKedatangan;
    int NomorKereta, harga;
};

JadwalKereta kereta[100];

void Data(JadwalKereta *arr, int &n){
    n = 0;

    arr[n++] = {"sinkansen Kalimantan", "Samarinda", "Balikpapan", "07:00", "08:30", 101, 250000};
    arr[n++] = {"sinkansen Kalimantan", "Balikpapan", "Penajam", "09:00", "11:00", 101, 320000};
    arr[n++] = {"sinkansen Kalimantan", "Penajam", "Tana Grogot", "11:30", "15:00", 101, 450000};
    arr[n++] = {"sinkansen Kalimantan", "Penajam", "Tana Grogot", "11:30", "15:00", 101, 450000};
    arr[n++] = {"sinkansen Kalimantan", "Penajam", "Balikpapan", "15:30", "17:30", 101, 320000};
    arr[n++] = {"sinkansen Kalimantan", "Balikpapan", "Samarinda", "18:00", "20:00", 101, 250000};
    arr[n++] = {"sinkansen Kalimantan", "Samarinda", "Tanjung Selor", "10:00", "01:00", 102, 765000};
    arr[n++] = {"sinkansen Kalimantan", "Samarinda", "Banjarmasin", "17:00", "19:30", 103, 745000};
    arr[n++] = {"Sinkansen Kalimantan", "Tanjung Selor", "Samarinda", "06:00", "19:00", 104, 765000};
    arr[n++] = {"sinkansen kalimantan", "Banjarmasin", "Samarinda",  "11:30", "00:00", 105, 745000};
    arr[n++] = {"Mahakam Train", "Samarinda", "Tanjung Selor", "07:00", "21:00", 201, 800000};
    arr[n++] = {"Mahakam Train", "Tanjung Selor", "Samarinda", "13:00", "03:00", 202, 800000};
    arr[n++] = {"Mahakam Train", "Samarinda", "Banjarmasin", "07:00", "19:30", 203, 800000};
    arr[n++] = {"Mahakam Train", "Banjarmasin", "Samarinda",  "11:30", "00:00", 204, 800000};
    arr[n++] = {"ZEN Train", "Banjarmasin", "Samarinda",  "11:30", "00:00", 501, 825000};
    arr[n++] = {"AAA CLAN Train", "BALIKPAPAN", "Samarinda",  "11:30", "00:00", 501, 254000};
}

void Tampil(JadwalKereta *arr, int n){
    for(int i = 0; i < n; i++){
        cout << endl;
        cout << "Nama Kereta  : " << (arr + i)->NamaKereta << endl;
        cout << "From         : " << (arr + i)->Asal << endl;
        cout << "To           : " << (arr + i)->Tujuan << endl ;
        cout << "Jam          : " << (arr + i)->JamKeberangkatan << " - " << (arr + i)->JamKedatangan << endl;
        cout << "Nomor Kereta : " << (arr + i)->NomorKereta << endl;
        cout << "Harga        : " << "Rp " << (arr + i)->harga << endl;
    }
}

void TambahData(JadwalKereta *arr, int &n){
    cout << "Masukkan jumlah data yang ingin ditambah: ";
    int jumlah;
    cin >> jumlah;
    cin.ignore();

    for(int i = 0; i < jumlah; i++){
        cout << "\nData ke-" << n+1 << endl;

        cout << "Nama Kereta : ";
        getline (cin, (arr + n)->NamaKereta);

        cout << "Asal : ";
        getline (cin, (arr + n)->Asal);

        cout << "Tujuan : ";
        getline (cin, (arr + n)->Tujuan);

        cout << "Jam Berangkat : ";
        getline (cin, (arr + n)->JamKeberangkatan);

        cout << "Jam Tiba : ";
        getline (cin, (arr + n)->JamKedatangan);

        cout << "Nomor Kereta : ";
        cin >> (arr + n)->NomorKereta;

        cout << "Harga : ";
        cin >> (arr + n)->harga;
        cin.ignore();

        n++;    
    }
}

string hurupkecil(string str){
    for(int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

void SearchRute(JadwalKereta *arr, int n){ // pake linear searching
    string asal, tujuan;
    cin.ignore();

    cout << "Masukkan Asal   : ";
    getline(cin, asal);
    cout << "Masukkan Tujuan : ";
    getline(cin, tujuan);

    bool ketemu = false;

    for(int i = 0; i < n; i++){
        cout << "Iterasi ke-" << i+1 << " : ";
        cout << (arr+i)->Asal << " -> " << (arr+i)->Tujuan << endl;
        if(hurupkecil((arr+i)->Asal) == hurupkecil(asal) && hurupkecil((arr+i)->Tujuan) == hurupkecil(tujuan)){
            JadwalKereta *p = arr + i;
            JadwalKereta temp = *p;
            *p = *(arr);
            *(arr) = temp;

            cout << "\nData ditemukan:\n";
            cout << "Nama : " << (arr)->NamaKereta << endl;
            cout << "Rute : " << (arr)->Asal << " - " << (arr)->Tujuan << endl;
            cout << "Harga: Rp " << (arr)->harga << endl;

            ketemu = true;
            break;
        }
    }

    if(!ketemu){
        cout << "Data tidak ditemukan!\n";
    }
}

void merge(JadwalKereta *arr, int l, int mid, int r){
    int i = l, j = mid+1, k = 0;
    JadwalKereta temp[100];

    while(i <= mid && j <= r){
        if(arr[i].NamaKereta < arr[j].NamaKereta)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];

    for(int i = 0; i < k; i++){
        arr[l+i] = temp[i];
    }
}

void MergeSort(JadwalKereta *arr, int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void SortNomor(JadwalKereta *arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i].NomorKereta > arr[j].NomorKereta){
                JadwalKereta *a = arr + i;
                JadwalKereta *b = arr + j;

                JadwalKereta temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }
}

void SearchKereta(JadwalKereta *arr, int n, int key){
    int step = sqrt(n);
    int prev = 0;

    while(arr[min(step, n)-1].NomorKereta < key){
        cout << "Loncat ke index " << step << endl;
        prev = step;
        step += sqrt(n);

        if(prev >= n){
            cout << "Data tidak ditemukan!\n";
            return;
        }
    }
    bool ketemu = false;

    for(int i = prev; i < min(step, n); i++){
        cout << "Cek index " << i << endl;

        if(arr[i].NomorKereta == key){
            ketemu = true;

            for(int j = 0; j < n; j++){
                if(arr[j].NomorKereta == key){
                    cout << "\nData ditemukan:\n";
                    cout << "Nama : " << (arr+j)->NamaKereta << endl;
                    cout << "Rute : " << (arr+j)->Asal << " - " << (arr+j)->Tujuan << endl;
                    cout << "Harga: Rp " << (arr+j)->harga << endl;
                }
            }
            return;
        }
    }

    if(!ketemu){
        cout << "Data tidak ditemukan!\n";
    }
}

void HargaTerendah(JadwalKereta *arr, int n){ // selection sorting untuk mengurutkan berdasarkan harga tiker termurah
    for(int i = 0; i < n-1; i++){
        int minIdx = i;

        for(int j = i+1; j < n; j++){
            if((arr+j)->harga < (arr+minIdx)->harga){
                minIdx = j;
            }
        }

        JadwalKereta temp = *(arr+i);
        *(arr+i) = *(arr+minIdx);
        *(arr+minIdx) = temp;
    }

    cout << "\nData diurutkan berdasarkan harga termurah!\n";
}

int main(){
    int n = 0;
    int pilih;
    Data(kereta,n);

    do{
        cout << endl;
        cout << "|==============================|" << endl;
        cout << "|1. TAMPILKAN KEBERANGKATAN    |" << endl;
        cout << "|2. TAMBAH DATA KEBERANGKATAN  |" << endl;
        cout << "|3. SEARCH MELALUI RUTE        |" << endl;
        cout << "|4. SEARCH MELALUI NOMOR KERETA|" << endl;
        cout << "|5. SESUAI NAMA KERETA (A-Z)   |" << endl;
        cout << "|6. FILTER HARGA TERMURAH      |" << endl;
        cout << "|7. KELUAR                     |" << endl;
        cout << "|==============================|" << endl;
        cout << "SILAHKAN MASUKKAN PILIHAN 1-7 : ";
        cin >> pilih;

        switch(pilih){
            case 1:{
                Tampil(kereta, n);
                break;
            }

            case 2 : {
                TambahData(kereta, n);
                break;
            }

            case 3 : {
                SearchRute(kereta, n);
                break;
            }

            case 4:{
                int key;
                cout << "Masukkan Nomor Kereta: ";
                cin >> key;

                SortNomor(kereta, n);
                SearchKereta(kereta, n, key);
                break;
            }

            case 5:{
                MergeSort(kereta, 0, n-1);
                cout << "Data berhasil diurutkan berdasarkan nama kereta!\n";
                Tampil(kereta, n);
                break;
            }

            case 6:{
                HargaTerendah(kereta, n);
                Tampil(kereta, n);
                break;
            }

            case 7:{
                cout << "TERIMA KASIH";
                break;
            }
        }
    }while(pilih != 7);

    return 0;
}