#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
auto start = high_resolution_clock::now();
    int data[] = {85, 12, 59, 45, 72, 51};
    int i, dataSize1 = sizeof(data);
    int dataSize = sizeof(data) / sizeof(data[0]), temp;
        
    for (int i = 0; i < dataSize; i++)
    {
        for (int j = 0; j < dataSize - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "\nData setelah sorting dengan bubble sort: \n";
    for (int i = 0; i < dataSize; i++)
    {
        cout << data[i] << " ";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count() / 1000.0 << " miliseconds" << endl;
    return 0;
}