#include <iostream>
#include <iomanip>
using namespace std;

// Fungsi untuk menukar dua elemen
void swap(long long &a, double &b) {
    long long temp = a;
    a = b;
    b = temp;
}

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mencetak array
void printData(long long NISN[], string Nama[], int Nilai[], int n) {
    cout << "\nData Siswa:" << endl;
    cout << setw(15) << "NISN" << setw(35) << "Nama" << setw(10) << "Nilai" << endl;
    cout << string(60, '-') << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(15) << NISN[i] << setw(35) << Nama[i] << setw(10) << Nilai[i] << endl;
    }
    cout << endl;
}

// Insertion Sort
void insertionSort(long long NISN[], string Nama[], int Nilai[], int n, int choice) {
    for(int i = 1; i < n; i++) {
        long long keyNISN = NISN[i];
        string keyNama = Nama[i];
        int keyNilai = Nilai[i];
        int j = i - 1;
        
        if(choice == 1) { // Sort by NISN
            while(j >= 0 && NISN[j] > keyNISN) {
                NISN[j+1] = NISN[j];
                Nama[j+1] = Nama[j];
                Nilai[j+1] = Nilai[j];
                j--;
            }
        } else { // Sort by Nilai
            while(j >= 0 && Nilai[j] > keyNilai) {
                NISN[j+1] = NISN[j];
                Nama[j+1] = Nama[j];
                Nilai[j+1] = Nilai[j];
                j--;
            }
        }
        NISN[j+1] = keyNISN;
        Nama[j+1] = keyNama;
        Nilai[j+1] = keyNilai;
    }
}

// Selection Sort
void selectionSort(long long NISN[], string Nama[], int Nilai[], int n, int choice) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(choice == 1) { // Sort by NISN
                if(NISN[j] < NISN[minIdx])
                    minIdx = j;
            } else { // Sort by Nilai
                if(Nilai[j] < Nilai[minIdx])
                    minIdx = j;
            }
        }
        if(minIdx != i) {
            swap(NISN[i], NISN[minIdx]);
            swap(Nama[i], Nama[minIdx]);
            swap(Nilai[i], Nilai[minIdx]);
        }
    }
}

// Bubble Sort
void bubbleSort(long long NISN[], string Nama[], int Nilai[], int n, int choice) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(choice == 1) { // Sort by NISN
                if(NISN[j] > NISN[j+1]) {
                    swap(NISN[j], NISN[j+1]);
                    swap(Nama[j], Nama[j+1]);
                    swap(Nilai[j], Nilai[j+1]);
                }
            } else { // Sort by Nilai
                if(Nilai[j] > Nilai[j+1]) {
                    swap(NISN[j], NISN[j+1]);
                    swap(Nama[j], Nama[j+1]);
                    swap(Nilai[j], Nilai[j+1]);
                }
            }
        }
    }
}

// Binary Search
int binarySearch(long long NISN[], int n, long long searchNISN) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(NISN[mid] == searchNISN)
            return mid;
        if(NISN[mid] < searchNISN)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Sequential Search and Update
void updateNilai60(string Nama[], int Nilai[], int n) {
    for(int i = 0; i < n; i++) {
        if(Nilai[i] == 60) {
            Nama[i] = "Joko";
        }
    }
}

int main() {
    const int n = 7;
    long long NISN[n] = {9960312699, 9963959682, 9950310962, 9970272750, 9970293945, 9952382180, 9965653989};
    string Nama[n] = {"Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentmo Uneputty", 
                      "Achmad Yaumil Fadjri R", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman"};
    int Nilai[n] = {90, 55, 80, 60, 70, 65, 60};
    
    int choice, sortChoice;
    
    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Urutkan Data" << endl;
        cout << "2. Cari NISN 9950310962" << endl;
        cout << "3. Ubah nama untuk nilai 60" << endl;
        cout << "4. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\nPilih metode pengurutan:" << endl;
                cout << "1. Insertion Sort" << endl;
                cout << "2. Selection Sort" << endl;
                cout << "3. Bubble Sort" << endl;
                cout << "Pilihan: ";
                cin >> sortChoice;
                
                cout << "\nUrutkan berdasarkan:" << endl;
                cout << "1. NISN" << endl;
                cout << "2. Nilai" << endl;
                cout << "Pilihan: ";
                int sortBy;
                cin >> sortBy;
                
                switch(sortChoice) {
                    case 1:
                        insertionSort(NISN, Nama, Nilai, n, sortBy);
                        break;
                    case 2:
                        selectionSort(NISN, Nama, Nilai, n, sortBy);
                        break;
                    case 3:
                        bubbleSort(NISN, Nama, Nilai, n, sortBy);
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
                printData(NISN, Nama, Nilai, n);
                break;
                
            case 2:
                {
                    // Sort first by NISN for binary search
                    bubbleSort(NISN, Nama, Nilai, n, 1);
                    int index = binarySearch(NISN, n, 9950310962);
                    if(index != -1) {
                        cout << "\nData ditemukan:" << endl;
                        cout << "NISN: " << NISN[index] << endl;
                        cout << "Nama: " << Nama[index] << endl;
                        cout << "Nilai: " << Nilai[index] << endl;
                    } else {
                        cout << "\nData tidak ditemukan!" << endl;
                    }
                }
                break;
                
            case 3:
                updateNilai60(Nama, Nilai, n);
                cout << "\nNama siswa dengan nilai 60 telah diubah menjadi 'Joko'" << endl;
                printData(NISN, Nama, Nilai, n);
                break;
                
            case 4:
                printData(NISN, Nama, Nilai, n);
                break;
                
            case 0:
                cout << "Program selesai." << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(choice != 0);
    
    return 0;
}