#include <bits/stdc++.h>

using namespace std;
int findLargestElement(int arr[], int n)
{

    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (mx < arr[i])
            mx = arr[i];

    return mx;
}
int main()
{
    int arr1[] = {2, 5, 1, 3, 0};
    int n = 5;
    int max = findLargestElement(arr1, n);
    cout << "The largest element in the array is: " << max << endl;

    int arr2[] = {8, 10, 5, 7, 9};
    n = 5;
    max = findLargestElement(arr2, n);
    cout << "The largest element in the array is: " << max << endl;
    return 0;
}
