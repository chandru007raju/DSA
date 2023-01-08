#include <bits/stdc++.h>
using namespace std;
bool linearSearch(int arr[], int size, int k)
{
    // base case
    if (size == 0)
        return false;

    if (arr[0] == k)
        return true;
    else
    {
        bool remainingPart = linearSearch(arr + 1, size - 1, k);
        return remainingPart;
    }
}

int main()
{
    int size, key;
    cin >> size;
    int *arr = new int[size];
    for (int i{0}; i < size; i++)
        cin >> arr[i];
    cin >> key;

    bool ans = linearSearch(arr, size, key);

    if (ans)
        cout << key << " is presnet" << endl;
    else
        cout << key << " is not presnet" << endl;
    delete[] arr;
    return 0;
}