#include <iostream>
using namespace std;

void reverseData(int *data, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = *(data + i);
        *(data + i) = *(data + size - 1 - i);
        *(data + size - 1 - i) = temp;
    }
}

int main() {

    int bilPrima[] = {2, 3, 5, 7, 11, 13, 17};
    int panjang = 7;

    cout << "Data Sebelum Reverse\n";
    cout << "----------------------\n";

    for (int i = 0; i < panjang; i++) {
        cout << "Isi = " << *(bilPrima + i)
            << " | Address = " << (bilPrima + i)
            << endl;
    }

    reverseData(bilPrima, panjang);

    cout << "\nData Setelah Reverse\n";
    cout << "----------------------\n";

    for (int i = 0; i < panjang; i++) {
        cout << "Isi = " << *(bilPrima + i)
            << " | Address = " << (bilPrima + i)
            << endl;
    }

    return 0;
}


// Soal 3 
// Array & Pointer - Operasi Dasar
// Buat program C++ yang menyimpan sejumlah data integer dalam array, lalu gunakan pointer untuk mengakses dan memanipulasi elemen-elemen tersebut.
// Deklarasikan array sesuai ketentuan masing-masing, lalu buat fungsi dengan parameter pointer untuk operasi yang diminta.

// • Deklarasikan array berisi 7 elemen yang diisi dengan bilangan prima (2, 3, 5, 7, 11, 13, 17).
// • Buat fungsi reverseArray(int* arr, int n) menggunakan pointer (bukan indeks) untuk membalik urutan array.
// • Tampilkan array sebelum dan sesudah dibalik.
// // Tampilkan pula alamat memori setiap elemen menggunakan pointer.