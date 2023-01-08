#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int index, int size)
{
    if (index == size)
        return;
    int curr = arr[index];
    int i = index - 1;
    while (i >= 0)
    {
        if (curr < arr[i])
            arr[i + 1] = arr[i--];
        else
            break;
    }
    arr[i + 1] = curr;
    insertionSort(arr, index + 1, size);
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
    insertionSort(arr, 1, size);
    printArray(arr, size);
    delete[] arr;
    return 0;
}