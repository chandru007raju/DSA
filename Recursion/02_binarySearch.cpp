#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k)
{ // element not found
    if (s > e)
        return false;

    int mid = s + (e - s) / 2;

    // element found
    if (arr[mid] == k)
        return true;

    if (arr[mid] < k)
        return binarySearch(arr, mid + 1, e, k);
    else
        return binarySearch(arr, s, mid - 1, k);
}

int main()
{
    int size, key;
    cin >> size;
    int *arr = new int[size];
    for (int i{0}; i < size; i++)
        cin >> arr[i];
    cin >> key;

    bool ans = binarySearch(arr, 0, size - 1, key);

    if (ans)
        cout << key << " is presnet" << endl;
    else
        cout << key << " is not presnet" << endl;
    delete[] arr;
    return 0;
}