#include <bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> v;
    long long int prod = 1, temp = 1;
    int f = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            f = 1;
            count++;
            continue;
        }
        prod *= nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (f == 1)
        {
            if (nums[i] == 0 && count == 1)
                v.push_back(prod);
            else
                v.push_back(0);
        }
        else
        {
            temp = prod / nums[i];
            v.push_back(temp);
        }
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> arr(n), vec(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vec = productExceptSelf(arr, n);

    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;

    return 0;
}