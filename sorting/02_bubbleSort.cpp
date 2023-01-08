#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
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
   
    bubbleSort(arr, n);
    cout<<"\nArray after sorting : ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    return 0;
}