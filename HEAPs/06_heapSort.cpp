#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;      // For 1 indexing based array.
    int right = 2 * i + 1; // For 1 indexing based array.

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    swap(arr[size], arr[1]);
    size--;

    heapify(arr, size, 1);
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    cout << "Heap : ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    heapSort(arr, n);
    cout << "Heap Sort : ";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    return 0;
}