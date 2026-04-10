#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100


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

Kereta dataKereta[MAX];
int jumlahKereta = 0;

Tiket antrian[MAX];
int front = -1, rear = -1;

Tiket riwayat[MAX];
int top = -1;

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

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama)
            *(arr + k) = L[i++];
        else
            *(arr + k) = R[j++];
        k++;
    }

    while (i < n1) *(arr + k++) = L[i++];
    while (j < n2) *(arr + k++) = R[j++];
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
        swap(arr + i, arr + minIdx);
    }
}

void enqueue(Tiket t) {
    if (rear == MAX - 1) {
        cout << "Antrian penuh\n";
        return;
    }
    if (front == -1) front = 0;

    rear++;
    *(antrian + rear) = t;

    cout << "Masuk antrian\n";
}

bool dequeue(Tiket *t) {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong\n";
        return false;
    }

    *t = *(antrian + front);
    front++;

    return true;
}

void tampilAntrian() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (int i = front; i <= rear; i++) {
        cout << (antrian + i)->namaPenumpang
            << " - " << (antrian + i)->rute << endl;
    }
}


void push(Tiket t) {
    if (top == MAX - 1) {
        cout << "Riwayat penuh\n";
        return;
    }

    top++;
    *(riwayat + top) = t;
}

void pop() {
    if (top == -1) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "Hapus transaksi: "
        << (riwayat + top)->namaPenumpang << endl;

    top--;
}

void tampilRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (int i = top; i >= 0; i--) {
        cout << (riwayat + i)->namaPenumpang
            << " - " << (riwayat + i)->rute << endl;
    }
}

void peek() {
    if (front != -1 && front <= rear)
        cout << "Depan antrian: "
            << (antrian + front)->namaPenumpang << endl;
    else
        cout << "Antrian kosong\n";

    if (top != -1)
        cout << "Terakhir riwayat: "
            << (riwayat + top)->namaPenumpang << endl;
    else
        cout << "Riwayat kosong\n";
}

int main() {
    int pilih;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari Nomor\n";
        cout << "5. Sort Nama\n";
        cout << "6. Sort Harga\n";
        cout << "7. Beli Tiket\n";
        cout << "8. Proses Tiket\n";
        cout << "9. Tampil Antrian\n";
        cout << "10. Tampil Riwayat\n";
        cout << "11. Hapus Riwayat\n";
        cout << "12. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tambah(dataKereta, jumlahKereta);
        else if (pilih == 2) tampil(dataKereta, jumlahKereta);
        else if (pilih == 3) {
            string asal, tujuan;
            cin.ignore();
            cout << "Asal: "; getline(cin, asal);
            cout << "Tujuan: "; getline(cin, tujuan);
            linearSearch(dataKereta, jumlahKereta, asal, tujuan);
        }

        else if (pilih == 4) {
            int key;
            cout << "Nomor: "; cin >> key;
            jumpSearch(dataKereta, jumlahKereta, key);
        }

        else if (pilih == 5) {
            mergeSort(dataKereta, 0, jumlahKereta - 1);
            cout << "Berhasil sort nama\n";
        }

        else if (pilih == 6) {
            selectionSort(dataKereta, jumlahKereta);
            cout << "Berhasil sort harga\n";
        }

        else if (pilih == 7) {
            Tiket t;
            cin.ignore();
            cout << "Nama: "; getline(cin, t.namaPenumpang);
            cout << "Rute: "; getline(cin, t.rute);
            enqueue(t);
        }

        else if (pilih == 8) {
            Tiket t;
            if (dequeue(&t)) {
                cout << "Diproses: " << t.namaPenumpang << endl;
                push(t);
            }
        }

        else if (pilih == 9) tampilAntrian();
        else if (pilih == 10) tampilRiwayat();
        else if (pilih == 11) pop();
        else if (pilih == 12) peek();

    } while (pilih != 0);

    return 0;
}