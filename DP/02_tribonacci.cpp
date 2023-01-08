#include <bits/stdc++.h>
using namespace std;

int tribonacciNum(int n, vector<int> &dp)
{

    if (dp[n] == -1)
    {
        int res;
        if (n <= 1)
            return n;
        else if (n == 2)
            return 1;
        else
            res = tribonacciNum(n - 1, dp) + tribonacciNum(n - 2, dp) + tribonacciNum(n - 3, dp);
        dp[n] = res;
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << tribonacciNum(n, dp) << endl;
    return 0;
}