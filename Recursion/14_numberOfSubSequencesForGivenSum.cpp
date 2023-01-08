#include <bits/stdc++.h>
using namespace std;

int firstSubSequencesWithGivenSum(int index, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        if (s == sum)
            return 1;
        else
            return 0;
    }
    s += arr[index];
    int left = firstSubSequencesWithGivenSum(index + 1, s, sum, arr, n);

    s -= arr[index];
    int right = firstSubSequencesWithGivenSum(index + 1, s, sum, arr, n);
    return left + right;
}

int main()
{
    int n, sum;
    cout << "Enter the size of arr : ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the sum : ";
    cin >> sum;

    cout<< firstSubSequencesWithGivenSum(0, 0, sum, arr, n);
    return 0;
}