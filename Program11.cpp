#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
int main()
{
    auto start = high_resolution_clock::now();
    int data[] = {85, 12, 59, 45, 72, 51};
    int i, dataSize = sizeof(data) / sizeof(data[0]), temp;
    for (int j = 1; j < dataSize; j++)
    {
        i = j - 1;
        temp = data[j];
        while (data[i] > temp && i >= 0)
        {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = temp;
    }
    cout << "\nData setelah sorting dengan insertion sort: \n";
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