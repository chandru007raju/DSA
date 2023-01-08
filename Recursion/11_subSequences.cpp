#include <bits/stdc++.h>
using namespace std;

void subSequences(int ind, vector<int> &ds, int arr[], int n)
{
    if (ind == n)
    {
        for (auto it : ds)
            cout << it << " ";
        if (ds.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }

    ds.push_back(arr[ind]);
    subSequences(ind + 1, ds, arr, n); // pick the particular index

    ds.pop_back();
    subSequences(ind + 1, ds, arr, n); // not pick the index
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ds;
    subSequences(0, ds, arr, n);
    return 0;
}