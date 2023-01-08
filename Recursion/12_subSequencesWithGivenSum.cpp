#include <bits/stdc++.h>
using namespace std;

void subSequencesWithGivenSum(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    subSequencesWithGivenSum(index + 1, ds, s, sum, arr, n);

    ds.pop_back();
    s -= arr[index];
    subSequencesWithGivenSum(index + 1, ds, s, sum, arr, n);
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

    subSequencesWithGivenSum(0, ds, 0, sum, arr, n);
    return 0;
}