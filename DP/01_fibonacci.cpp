#include <bits/stdc++.h>
using namespace std;

int fibSeries(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (fibSeries(n - 1, dp) + fibSeries(n - 2, dp)) % int (1e9 + 7);
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibSeries(n, dp) << endl;
    return 0;
}