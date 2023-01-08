#include <bits/stdc++.h>
using namespace std;

bool firstSubSequencesWithGivenSum(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        else
            return false;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    if (firstSubSequencesWithGivenSum(index + 1, ds, s, sum, arr, n) == true)
        return true;

    ds.pop_back();
    s -= arr[index];
    if (firstSubSequencesWithGivenSum(index + 1, ds, s, sum, arr, n) == true)
        return true;
    return false;
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
    vector<int> ds;

    firstSubSequencesWithGivenSum(0, ds, 0, sum, arr, n);
    return 0;
}