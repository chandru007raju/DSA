#include <bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int n)
{
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    int i = 0, p = 0, k = 0;
    while (p < pos.size() && k < neg.size())
    {
        if (i % 2 == 0)
            arr[i++] = pos[p++];
        else
            arr[i++] = neg[k++];
    }
    while (p < pos.size())
        arr[i++] = pos[p++];
    while (k < neg.size())
        arr[i++] = neg[k++];
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    rearrange(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    delete [] arr;
    return 0;
}