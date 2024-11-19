#include <iostream> // Include the library for input/output operations

using namespace std; // Use the standard namespace to simplify syntax


// Function to perform insertion sort

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) { // Iterate through the array starting from the second element

        int key = arr[i]; // Store the current element as "key"

        int j = i - 1; // Set j to the index before i



        // Move elements of the sorted part that are greater than key one position ahead

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j]; // Shift the element at index j to index j + 1

            j--; // Move one step back in the array

        }



        arr[j + 1] = key; // Place the key in its correct sorted position

    }

}



// Function to perform selection sort

void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) { // Iterate through the array, leaving the last element

        int minIndex = i; // Assume the current index is the smallest

        for (int j = i + 1; j < n; j++) { // Iterate through the remaining unsorted part of the array

            if (arr[j] < arr[minIndex]) { // If a smaller element is found

                minIndex = j; // Update minIndex to this smaller element's index

            }

        }

        swap(arr[i], arr[minIndex]); // Swap the smallest element with the first element of the unsorted part

    }

}



// Function to perform bubble sort

void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) { // Iterate through the array n-1 times

        for (int j = 0; j < n - i - 1; j++) { // Iterate through the unsorted part of the array

            if (arr[j] > arr[j + 1]) { // If the current element is larger than the next

                swap(arr[j], arr[j + 1]); // Swap the two elements

            }

        }

    }

}



// Function to merge two sorted subarrays

void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1; // Size of the left subarray

    int n2 = right - mid; // Size of the right subarray



    int L[n1], R[n2]; // Temporary arrays to store the two halves



    // Copy data to temporary arrays

    for (int i = 0; i < n1; i++)

        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)

        R[i] = arr[mid + 1 + i];



    int i = 0, j = 0, k = left; // Initialize indices for left, right, and merged array

    while (i < n1 && j < n2) { // Merge elements back into the original array

        if (L[i] <= R[j]) { // If the element in the left array is smaller

            arr[k++] = L[i++]; // Place it into the original array

        } else { // If the element in the right array is smaller

            arr[k++] = R[j++];

        }

    }



    // Copy remaining elements of L[], if any

    while (i < n1)

        arr[k++] = L[i++];



    // Copy remaining elements of R[], if any

    while (j < n2)

        arr[k++] = R[j++];

}



// Function to perform merge sort

void mergeSort(int arr[], int left, int right) {

    if (left < right) { // Base condition: stop when the subarray has 1 or no elements

        int mid = left + (right - left) / 2; // Find the middle point



        mergeSort(arr, left, mid); // Recursively sort the left half

        mergeSort(arr, mid + 1, right); // Recursively sort the right half



        merge(arr, left, mid, right); // Merge the two halves

    }

}



// Function to partition the array and return the pivot index

int partition(int arr[], int low, int high) {

    int pivot = arr[high]; // Choose the last element as the pivot

    int i = low - 1; // Initialize the smaller element index



    for (int j = low; j < high; j++) { // Iterate through the array

        if (arr[j] < pivot) { // If the current element is smaller than the pivot

            i++; // Move the smaller element index forward

            swap(arr[i], arr[j]); // Swap the smaller element with the current element

        }

    }

    swap(arr[i + 1], arr[high]); // Place the pivot in the correct position

    return i + 1; // Return the index of the pivot

}



// Function to perform quick sort

void quickSort(int arr[], int low, int high) {

    if (low < high) { // Base condition: stop when the subarray has 1 or no elements

        int pi = partition(arr, low, high); // Partition the array and get the pivot index



        quickSort(arr, low, pi - 1); // Recursively sort the left part

        quickSort(arr, pi + 1, high); // Recursively sort the right part

    }

}



int main() {

    int arr[] = {5, 3, 4, 1, 2}; // Define an array of integers to be sorted

    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array



    cout << "Pilih metode pengurutan:\n";

    cout << "1. Insertion Sort\n";

    cout << "2. Selection Sort\n";

    cout << "3. Bubble Sort\n";

    cout << "4. Merge Sort\n";

    cout << "5. Quick Sort\n";

    cout << "Masukkan pilihan: ";

    int choice;

    cin >> choice; // Take the user's choice



    switch (choice) {

    case 1:

        insertionSort(arr, n); // Call insertion sort

        break;

    case 2:

        selectionSort(arr, n); // Call selection sort

        break;

    case 3:

        bubbleSort(arr, n); // Call bubble sort

        break;

    case 4:

        mergeSort(arr, 0, n - 1); // Call merge sort

        break;

    case 5:

        quickSort(arr, 0, n - 1); // Call quick sort

        break;

    default:

        cout << "Pilihan tidak valid.\n";

        return 1; // Exit the program with an error code

    }



    cout << "Hasil pengurutan: ";

    for (int i = 0; i < n; i++) // Loop through the sorted array

        cout << arr[i] << " "; // Print each element followed by a space

    cout << endl;



    return 0; // Indicate successful completion of the program

}

