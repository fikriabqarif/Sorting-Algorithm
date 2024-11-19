#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int Data[] = {85, 12, 59, 45, 72, 51};
int Max = sizeof(Data)/sizeof(Data[0]);

void merge(int low, int mid, int high)
{
    int temp[Max]; 
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (Data[i] <= Data[j])
        {
            temp[k++] = Data[i++];
        }
        else
        {
            temp[k++] = Data[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = Data[i++];
    }

    while (j <= high)
    {
        temp[k++] = Data[j++];
    }

    for (i = low; i <= high; i++)
    {
        Data[i] = temp[i];
    }
}

void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{

    auto start = high_resolution_clock::now();

    cout << "Data sebelum sorting: " << endl;
    for (int i = 0; i < Max; i++)
    {
        cout << Data[i] << " ";
    }
    cout << endl;

    merge_sort(0, Max - 1);  

    cout << "Data setelah sorting: " << endl;
    for (int i = 0; i < Max; i++) 
    {
        cout << Data[i] << " ";
    }
    cout << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() / 1000.0 << " milliseconds" << endl;

    return 0;
}