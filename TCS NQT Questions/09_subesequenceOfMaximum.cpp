#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v;
    v.push_back(a[0]);
    for (int i = 0; i < n; i++)
    {
        int lastIndex = v.size() - 1;
        int k = v[lastIndex];
        if (k == 0)
            v[lastIndex] = a[i];
        else if (a[i] == 0)
            continue;
        else if (a[i] < 0)
        {
            if (v[lastIndex] < 0)
                v[lastIndex] = max(v[lastIndex], a[i]);
            else
                v.push_back(a[i]);
        }
        else
        {
            if (v[lastIndex] > 0)
                v[lastIndex] = max(v[lastIndex], a[i]);
            else
                v.push_back(a[i]);
        }
    }

    int sum = 0;
    for (auto it : v)
        sum += it;
    cout << sum << endl;

    return 0;
}