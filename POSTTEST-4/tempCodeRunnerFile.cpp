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

struct Tiket {
    string namaPenumpang;
    string rute;
};

struct Node {
    Tiket data;
    Node* next;
};

Kereta dataKereta[100];
int jumlahKereta = 0;

Node* depan = NULL;
Node* belakang = NULL;
Node* atas = NULL;

void tukar(Kereta *a, Kereta *b) {
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
    cout << "\nNomor Kereta: ";
    cin >> (arr + n)->nomor;
    cin.ignore();
    cout << "Nama Kereta: ";
    getline(cin, (arr + n)->nama);
    cout << "Asal: ";
    getline(cin, (arr + n)->asal);
    cout << "Tujuan: ";
    getline(cin, (arr + n)->tujuan);
    cout << "Harga: ";
    cin >> (arr + n)->harga;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool found = false;
    cout << "\nProses pencarian linear:\n";

    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            found = true;
        }
    }

    if (!found) cout << "Data tidak ditemukan\n";
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

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

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama)
            *(arr + k) = L[i++];
        else
            *(arr + k) = R[j++];
        k++;
    }

    while (i < n1)
        *(arr + k++) = L[i++];

    while (j < n2)
        *(arr + k++) = R[j++];
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
            if ((arr + j)->harga < (arr + minIdx)->harga)
                minIdx = j;
        }
        tukar(arr + i, arr + minIdx);
    }
}

void tambahAntrian(Tiket t) {
    Node* baru = new Node{t, NULL};

    if (belakang == NULL) {
        depan = belakang = baru;
    } else {
        belakang->next = baru;
        belakang = baru;
    }

    cout << "Berhasil masuk antrian\n";
}

bool prosesAntrian(Tiket *t) {
    if (depan == NULL) {
        cout << "Antrian kosong\n";
        return false;
    }

    Node* hapus = depan;
    *t = hapus->data;

    depan = depan->next;

    if (depan == NULL)
        belakang = NULL;

    delete hapus;
    return true;
}

void tampilAntrian() {
    if (depan == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Node* bantu = depan;

    cout << "\n=== ANTRIAN ===\n";

    while (bantu != NULL) {
        cout << bantu->data.namaPenumpang
            << " - " << bantu->data.rute << endl;
        bantu = bantu->next;
    }
}

void simpanRiwayat(Tiket t) {
    Node* baru = new Node{t, NULL};
    baru->next = atas;
    atas = baru;
}

void hapusRiwayat() {
    if (atas == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* hapus = atas;

    cout << "Menghapus data riwayat: "
        << hapus->data.namaPenumpang << endl;

    atas = atas->next;
    delete hapus;
}

void tampilRiwayat() {
    if (atas == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* bantu = atas;

    cout << "\n=== RIWAYAT ===\n";

    while (bantu != NULL) {
        cout << bantu->data.namaPenumpang
            << " - " << bantu->data.rute << endl;
        bantu = bantu->next;
    }
}

void lihatData() {
    if (depan != NULL)
        cout << "Antrian terdepan: " << depan->data.namaPenumpang << endl;
    else
        cout << "Antrian kosong\n";

    if (atas != NULL)
        cout << "Riwayat terakhir: " << atas->data.namaPenumpang << endl;
    else
        cout << "Riwayat kosong\n";
}


int main() {
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari Nomor\n";
        cout << "5. Urutkan Nama\n";
        cout << "6. Urutkan Harga\n";
        cout << "7. Beli Tiket (Tambah Antrian)\n";
        cout << "8. Proses Tiket \n";//(Proses Antrian lalu di simpan keriwayat)
        cout << "9. Tampilkan Antrian\n";
        cout << "10. Tampilkan Riwayat\n";
        cout << "11. Hapus Riwayat\n";
        cout << "12. Lihat Data Teratas\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";

        cin >> pilih;

        if (pilih == 1) tambah(dataKereta, jumlahKereta);
        else if (pilih == 2) tampil(dataKereta, jumlahKereta);
        else if (pilih == 3) {
            string asal, tujuan;
            cin.ignore();
            cout << "Asal: ";
            getline(cin, asal);
            cout << "Tujuan: ";
            getline(cin, tujuan);
            linearSearch(dataKereta, jumlahKereta, asal, tujuan);
        }
        else if (pilih == 4) {
            int key;
            cout << "Nomor: ";
            cin >> key;
            jumpSearch(dataKereta, jumlahKereta, key);
        }
        else if (pilih == 5) {
            mergeSort(dataKereta, 0, jumlahKereta - 1);
            cout << "Berhasil mengurutkan nama\n";
        }
        else if (pilih == 6) {
            selectionSort(dataKereta, jumlahKereta);
            cout << "Berhasil mengurutkan harga\n";
        }
        else if (pilih == 7) {
            Tiket t;
            cin.ignore();
            cout << "Nama: ";
            getline(cin, t.namaPenumpang);
            cout << "Rute: ";
            getline(cin, t.rute);
            tambahAntrian(t);
        }
        else if (pilih == 8) {
            Tiket t;
            if (prosesAntrian(&t)) {
                cout << "Diproses: " << t.namaPenumpang << endl;
                simpanRiwayat(t);
            }
        }
        else if (pilih == 9) tampilAntrian();
        else if (pilih == 10) tampilRiwayat();
        else if (pilih == 11) hapusRiwayat();
        else if (pilih == 12) lihatData();
    } while (pilih != 0);
    return 0;
}