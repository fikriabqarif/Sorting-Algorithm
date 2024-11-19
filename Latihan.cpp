#include <iostream>
#include <iomanip>
using namespace std;

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
void cetak(long long NISN[], string Nama[], int Nilai[], int n) {
    cout << "\nData Siswa:" << endl;
    cout << setw(15) << "NISN" << setw(35) << "Nama" << setw(10) << "Nilai" << endl;
    cout << "===============================" << endl;
    for(int i = 0; i < n; i++) {
        cout << setw(15) << NISN[i] << setw(35) << Nama[i] << setw(10) << Nilai[i] << endl;
    }
    cout << endl;
}
void sisipan(long long NISN[], string Nama[], int Nilai[], int n, int pilih) {
    for(int i = 1; i < n; i++) {
        long long tempNISN = NISN[i];
        string keyNama = Nama[i];
        int tempNilai = Nilai[i];
        int j = i - 1;
        
        if(pilih == 1) { // urutkan dari NISN
            while(j >= 0 && NISN[j] > tempNISN) {
                NISN[j+1] = NISN[j];
                Nama[j+1] = Nama[j];
                Nilai[j+1] = Nilai[j];
                j--;
            }
        } else { // urutkan dari Nilai
            while(j >= 0 && Nilai[j] > tempNilai) {
                NISN[j+1] = NISN[j];
                Nama[j+1] = Nama[j];
                Nilai[j+1] = Nilai[j];
                j--;
            }
        }
        NISN[j+1] = tempNISN;
        Nama[j+1] = keyNama;
        Nilai[j+1] = tempNilai;
    }
}
// Selection Sort 
void seleksi(long long NISN[], string Nama[], int Nilai[], int n, int pilih) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(pilih == 1) { // urutan dari NISN
                if(NISN[j] < NISN[minIdx])
                    minIdx = j;
            } else { // urutan dari Nilai
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

//gelembung 
void gelembung(long long NISN[], string Nama[], int Nilai[], int n, int pilih) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(pilih == 1) { // urutan dari NISN
                if(NISN[j] > NISN[j+1]) {
                    swap(NISN[j], NISN[j+1]);
                    swap(Nama[j], Nama[j+1]);
                    swap(Nilai[j], Nilai[j+1]);
                }
            } else { // urutan dari Nilai
                if(Nilai[j] > Nilai[j+1]) {
                    swap(NISN[j], NISN[j+1]);
                    swap(Nama[j], Nama[j+1]);
                    swap(Nilai[j], Nilai[j+1]);
                }
            }
        }
    }
}

// search binary
int binary(long long NISN[], int n, long long cari) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(NISN[mid] == cari)
            return mid;
        if(NISN[mid] < cari)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// ubah ke nama joko
void ubahjoko(string Nama[], int Nilai[], int n) {
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
    
    int pilih, sortpilih;
    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Urutkan Data" << endl;
        cout << "2. Cari NISN 9950310962" << endl;
        cout << "3. Ubah nama untuk nilai 60" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilih;
        
        switch(pilih) {
            case 1:
                cout << "\nPilih metode pengurutan:" << endl;
                cout << "1. Insertion Sort" << endl;
                cout << "2. Selection Sort" << endl;
                cout << "3. Bubble Sort" << endl;
                cout << "Pilihan: ";
                cin >> sortpilih;
                
                cout << "\nUrutkan berdasarkan:" << endl;
                cout << "1. NISN" << endl;
                cout << "2. Nilai" << endl;
                cout << "Pilihan: ";
                int sortBy;
                cin >> sortBy;
                
                switch(sortpilih) {
                    case 1:
                        sisipan(NISN, Nama, Nilai, n, sortBy);
                        break;
                    case 2:
                        seleksi(NISN, Nama, Nilai, n, sortBy);
                        break;
                    case 3:
                        gelembung(NISN, Nama, Nilai, n, sortBy);
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
                cetak(NISN, Nama, Nilai, n);
                break;
                
            case 2:
                {
                    gelembung(NISN, Nama, Nilai, n, 1);
                    int index = binary(NISN, n, 9950310962);
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
                ubahjoko(Nama, Nilai, n);
                cout << "\nNama siswa dengan nilai 60 telah diubah menjadi 'Joko'" << endl;
                cetak(NISN, Nama, Nilai, n);
                break;
                
            case 0:
                break;
                
            default:
                cout << "Salah!" << endl;
        }
    } while(pilih != 0);
    
    return 0;
}