#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(9);
    arr.push_back(2);

    int n = arr.size();
    cout<<"Array before sorting : ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    selectionSort(arr, n);
    cout<<"\nArray After sorting : ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    return 0;
}