#include <iostream>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

#define MAX 100
void swap(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}
void tampil(Kereta *arr, int n) {
    cout << "\n---------- Jadwal Kereta ----------\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->nomor << " | "
            << (arr + i)->nama << " | "
            << (arr + i)->asal << " -> "
            << (arr + i)->tujuan << " | Harga: "
            << (arr + i)->harga << endl;
    }
}
void tambah(Kereta *arr, int &n) { 
    cout << "\nNomor Kereta: "; cin >> (arr + n)->nomor;
    cin.ignore();
    cout << "Nama Kereta: "; getline(cin, (arr + n)->nama);
    cout << "Asal: "; getline(cin, (arr + n)->asal);
    cout << "Tujuan: "; getline(cin, (arr + n)->tujuan);
    cout << "Harga: "; cin >> (arr + n)->harga;
    n++;
}
void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool found = false;
    cout << "\nProses Linear Search:\n";

    for (int i = 0; i < n; i++) {
        cout << "Cek data ke-" << i << endl;
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            found = true;
        }
    }

    if (!found) cout << "Data tidak ditemukan\n";
}
    int min(int a, int b) { return (a < b) ? a : b; }

    void jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;
    while ((arr + min(step, n) - 1)->nomor < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Data tidak ditemukan\n";
            return;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        if ((arr + i)->nomor == key) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            return;
        }
    }

    cout << "Data tidak ditemukan\n";
}
void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Kereta L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);
    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            *(arr + k) = L[i];
            i++;
        } else {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = L[i];
        i++; k++;
    }

    while (j < n2) {
        *(arr + k) = R[j];
        j++; k++;
    }
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }

        swap(arr + i, arr + minIdx); 
    }
}

int main() {
    Kereta data[MAX];
    int n = 0;
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Rute \n";
        cout << "4. Cari Nomor kereta \n";
        cout << "5. Sort Nama kereta \n";
        cout << "6. Sort Harga tiket\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
    
        if (pilih == 1) {
            tambah(data, n);
        }
        else if (pilih == 2) {
            tampil(data, n);
        }
        else if (pilih == 3) {
            string asal, tujuan;
            cin.ignore();
            cout << "Asal kereta: "; getline(cin, asal);
            cout << "Tujuan kereta: "; getline(cin, tujuan);
            linearSearch(data, n, asal, tujuan);
        }
        else if (pilih == 4) {
            int key;
            cout << "Nomor kereta: "; cin >> key;
            jumpSearch(data, n, key);
        }
        else if (pilih == 5) {
            mergeSort(data, 0, n - 1);
            cout << "Berhasil menggurutkan berdasarkan nama kereta \n";
        }
        else if (pilih == 6) {
            selectionSort(data, n);
            cout << "Berhasi menggurutkan berdasarkan harga tiket\n";
        }
    } while (pilih != 0);
    return 0;
}