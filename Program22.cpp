#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();
    int data[] = {85, 12, 59, 45, 72, 51};
    int loc, i, dataSize = sizeof(data) / sizeof(data[0]), min, temp;
    for (int i = 1; i < dataSize; i++)
    {
        min = data[i];
        loc = i;
        if (min > data[i])
        {
            min = data[i];
            loc = i;
        }
        temp = data[i];
        data[i] = data[loc];
        data[loc] = temp;
    }
    cout << "\nData setelah sorting dengan selection sort: \n";
    for (int j = 0; j < dataSize; j++)
    {
        cout << data[j] << " ";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() / 1000.0 << " miliseconds" << endl;

    return 0;
}