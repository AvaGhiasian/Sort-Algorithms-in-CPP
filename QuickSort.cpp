#include <iostream>

using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[left], i = left + 1, j = right;

    while (i <= j)
    {
        while (i <= right && arr[i] < pivot)
            i++;
        while (j >= left && arr[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // or swap(arr[i], arr[j]);
        }
    }
    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;
    // or swap(arr[i + 1], arr[right]);

    return j; // pivot index
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);  // sort left side
        quickSort(arr, pivotIndex + 1, right); // sort right side
    }
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

    cout << "Quick Sort in Ascending Order:" << endl;
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

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}