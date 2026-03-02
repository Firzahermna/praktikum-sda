#include <iostream>
using namespace std;

struct DataMahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    const int jumlah = 5;
    DataMahasiswa data[jumlah];

    cout << "=== INPUT DATA MAHASISWA ===" << endl;

    for(int i = 0; i < jumlah; i++) {

        cout << "\nData ke-" << i+1 << endl;

        cout << "Masukkan Nama : ";
        getline(cin, data[i].nama);

        cout << "Masukkan NIM  : ";
        cin >> data[i].nim;

        cout << "Masukkan IPK  : ";
        cin >> data[i].ipk;

        cin.ignore(); 
    }

    int posisiTertinggi = 0;

    for(int i = 1; i < jumlah; i++) {
        if(data[i].ipk > data[posisiTertinggi].ipk) {
            posisiTertinggi = i;
        }
    }

    cout << "\n--------------- HASIL ---------------" << endl;
    cout << "Mahasiswa dengan IPK paling tinggi adalah:" << endl;
    cout << "Nama : " << data[posisiTertinggi].nama << endl;
    cout << "NIM  : " << data[posisiTertinggi].nim << endl;
    cout << "IPK  : " << data[posisiTertinggi].ipk << endl;

    return 0;
}

// soal:
// Struct + Array Data Mahasiswa
// Buat program C++ menggunakan struct Mahasiswa yang memiliki field: nama (string), nim (string), dan ipk (float).
// Deklarasikan array of struct sesuai jumlah mahasiswa yang diminta, lakukan input data, lalu tampilkan hasil sesuai ketentuan.

// • Input data 5 mahasiswa (nama, NIM, IPK).
// • Cari dan tampilkan mahasiswa dengan IPK tertinggi.