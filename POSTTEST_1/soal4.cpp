#include <iostream>
using namespace std;

// void swapNilai(int *p1, int *p2) {
//     int sementara = *p1;
//     *p1 = *p2;
//     *p2 = sementara;
// }

// int main() {

//     int angka1 = 25;
//     int angka2 = 90;

//     cout << "===== DATA SEBELUM DITUKAR =====\n";
//     cout << "Angka 1 --> " << angka1 << endl;
//     cout << "Angka 2 --> " << angka2 << endl;

//     swapNilai(&angka1, &angka2);

//     cout << "\n===== DATA SETELAH DITUKAR =====\n";
//     cout << "Angka 1 --> " << angka1 << endl;
//     cout << "Angka 2 --> " << angka2 << endl;

//     return 0;
// }


// Soal 4. Pointer pada Fungsi
// Buat fungsi untuk menukar dua variabel integer.
// · gunakan pointer dalam fungsi untuk melakukan pertukaran nilai.
// · Uji fungsi tersebut dengan dua nilai input dan tampilkan hasil sebelum dan sesudah pertukaran.

struct Mahasiswa {
    string nama;
    int umur;
};
int main() {
    Mahasiswa mhs1;
    mhs1.nama = "asep";
    mhs1.umur = 21;
    cout << mhs1.nama << endl;
    cout << mhs1.umur << endl;
}