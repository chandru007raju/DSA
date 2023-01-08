#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int index, int size)
{
    if (index == size)
        return;

    int smallIndex = index;

    for (int i = index + 1; i < size; i++)
    {
        if (arr[smallIndex] > arr[i])
            smallIndex = i;
    }

    swap(arr[index], arr[smallIndex]);
    selectionSort(arr, index + 1, size);
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
    selectionSort(arr, 0, size);
    printArray(arr, size);
    delete[] arr;
    return 0;
}