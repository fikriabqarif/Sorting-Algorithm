#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
    auto start = high_resolution_clock::now();
    bool found = false;
    const char *nama[] = {"Adi", "Budi", "Charli", " Dodi", "Edi"};
    const char *nomorInduk[] = {"10101", "10103", "10105", "10102", "10104"};
    const char *query = "10105";
    float nilai[] = {64.75, 75.11, 84.63, 77.07, 66.70};
    for (int i = 0; i < 5; i++)
    {
        if (nomorInduk[i] == query)
        {
            cout << nama[i] << "," << nomorInduk[i] << "," << nilai[i] << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Tidak ditemukan. ";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() / 1000.0 << " miliseconds" << endl;

    return 0;
}