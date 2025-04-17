#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int left_size = mid - left + 1; // size of left subarray
    int right_size = right - mid;   // size of right subarray

    int left_arr[left_size], right_arr[right_size]; // creating temp arrays

    // copying data into temp arrays
    for (int i = 0; i < left_size; i++)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < right_size; j++)
        right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // merge temp arrays back into arr[]
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    int size;

    cout << "Merge Sort:" << endl;
    cout << "Enter number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " random integers to be sorted: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
