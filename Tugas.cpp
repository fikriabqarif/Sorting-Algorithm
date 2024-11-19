#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;

void SortingNaik(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void SortingTurun(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void sequence(int arr[], int n, int target) {
    bool found = false;
    cout << "Sequential Search untuk angka " << target << ": ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Ditemukan pada indeks " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ditemukan" << endl;
    }
}

int binary(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    auto start = high_resolution_clock::now();
    int arr[] = {10,4,5,1,2,3,6,8,1,2,5,8,3,8,1,2,3,8,9,21,35,72,89,99,78};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int arrAsc[n], arrDesc[n];
    for(int i = 0; i < n; i++) {
        arrAsc[i] = arr[i];
        arrDesc[i] = arr[i];
    }
    
    cout << "Array awal: ";
    printArray(arr, n);
    
    SortingNaik(arrAsc, n);
    cout << "\nHasil pengurutan ascending: ";
    printArray(arrAsc, n);
    
    SortingTurun(arrDesc, n);
    cout << "Hasil pengurutan descending: ";
    printArray(arrDesc, n);
    
    cout << "\nHasil Sequential Search:\n";
    sequence(arr, n, 15);
    sequence(arr, n, 1);
    
    cout << "\nHasil Binary Search:\n";
    int result15 = binary(arrAsc, 0, n-1, 15);
    cout << "Binary Search untuk angka 15: ";
    if (result15 == -1)
        cout << "Tidak ditemukan" << endl;
    else
        cout << "Ditemukan pada indeks " << result15 << endl;
        
    int result1 = binary(arrAsc, 0, n-1, 1);
    cout << "Binary Search untuk angka 1: ";
    if (result1 == -1)
        cout << "Tidak ditemukan" << endl;
    else
        cout << "Ditemukan pada indeks " << result1 << endl;
        
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() / 1000.0 << " miliseconds" << endl;

    return 0;
}