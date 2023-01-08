// Write a program to reverse an array

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int size)
{
    int s = 0, e = size - 1;
    while (s < e)
    {
        swap(arr[s++], arr[e--]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array Before Swap"<<endl;
    printArray(arr, size);
    reverseArray(arr, size);
    cout<<"Array After Swap"<<endl;
    printArray(arr, size);
    return 0;
}