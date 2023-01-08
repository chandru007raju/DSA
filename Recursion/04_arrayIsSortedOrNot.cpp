#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size)
{
    // base case
    if (size == 0 || size == 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    else
        return isSorted(arr + 1, size - 1);
}
int main()
{
    // 3 5 7 9 8
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i{0}; i < size; i++)
        cin >> arr[i];

    bool ans = isSorted(arr, size);

    if (ans)
        cout << "Array is Sorted" << endl;
    else
        cout << "Array is not Sorted" << endl;
    delete[] arr;
    return 0;
}