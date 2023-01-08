#include <bits/stdc++.h>
using namespace std;
void getElements(int arr[], int n)
{
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    cout << "smallest is " << small << endl;
    cout << "largest is " << large << endl;
    cout << endl;
    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}

int main()
{
    int arr[] = {7, 12, 1, 9, 3, 6, 10, 18, 5, 15};
    // Sorted -> 1, 3, 5, 6, 7, 9, 10, 12, 15, 18
    int n = sizeof(arr) / sizeof(arr[0]);
    getElements(arr, n);
    return 0;
}