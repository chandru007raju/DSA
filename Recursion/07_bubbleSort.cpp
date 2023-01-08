#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size)
{
    if (size == 0 || size == 1)
        return;
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);

    bubbleSort(arr, size - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i{0}; i < size; i++)
        cin >> arr[i];
    bubbleSort(arr, size);
    printArray(arr, size);
    delete[] arr;
    return 0;
}