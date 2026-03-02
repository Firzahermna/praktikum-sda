#include <iostream>
using namespace std;

// Analisis sederhana:

// Langkah:
// 1. Ambil elemen pertama sebagai nilai awal minimum
// 2. Bandingkan dengan semua elemen berikutnya
// 3. Jika ada yang lebih kecil, ganti minimum
// 4. Kembalikan hasilnya

// Kompleksitas:
// Perulangan jalan sebanyak (n-1)
// Jadi waktu eksekusi = O(n)
// Best case  = O(n)
// Worst case = O(n)


int FindMin(int arr[], int n)
{
    int minValue = arr[0];   // asumsi awal

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < minValue)
        {
            minValue = arr[i];
        }
    }
    return minValue;
}
int main()
{
    int data[8] = {9, 4, 12, 7, 2, 15, 6, 3};
    int n = 8;

    int hasilMin = FindMin(data, n);
    int indexMin = 0;

    for(int i = 0; i < n; i++)
    {
        if(data[i] == hasilMin)
        {
            indexMin = i;
            break;
        }
    }

    cout << "Minimum : " << hasilMin << endl;
    cout << "Index   : " << indexMin << endl;

    return 0;
}