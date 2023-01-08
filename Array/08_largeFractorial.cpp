#include <bits/stdc++.h>
using namespace std;
vector<long long> factorial(vector<long long> a, int n)
{
    int m = 1e9 + 7;
    long long mx = *max_element(a.begin(), a.end());
    vector<long long> ans, dp(mx + 1, 1);
    for (long long i = 1; i <= mx; i++)
    {
        dp[i] = (i * dp[i - 1]) % m;
    }
    for (auto it : a)
    {
        ans.push_back(dp[it]);
    }
    return ans;
}
int main()
{
    int n, i;
    cin >> n;
    vector<long long> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> res = factorial(a, n);
    for (i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}