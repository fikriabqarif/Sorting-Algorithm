#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    auto start = high_resolution_clock::now();
    bool found = false;
    int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i = 0, j = sizeof(data) / sizeof(data[0]), k, query = 10;
    while (!found && i <= j){
        k = (i + j) / 2;
        if (data[k] < query){
            i = k + 1;
        }
        else if (data[k] == query){
            found = true;
        }
        else{
            j = k - 1;
        }
    }
    if (!found){
        cout << "Tidak ditemukan. ";
    }
    else{
        cout << "Ditemukan";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() / 1000.0 << " miliseconds" << endl;
    return 0;
}