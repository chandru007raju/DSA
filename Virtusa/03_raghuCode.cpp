#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long n;
    cin >> n;

    vector<vector<long long>> matrix(n, vector<long long>(n));
    for (long i = 0; i < n; i++)
    {
        for (long j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (long i = 0; i < n; i++)
    {
        dp[n - 1][i] = matrix[n - 1][i];
    }

    for (long i = n - 2; i >= 0; i--)
    {
        for (long j = 0; j < n; j++)
        {
            long long maxx = dp[i + 1][j];
            if (j - 1 >= 0)
            {
                maxx = max(maxx, dp[i + 1][j - 1]);
            }
            if (j + 1 < n)
            {
                maxx = max(maxx, dp[i + 1][j + 1]);
            }

            dp[i][j] = maxx + matrix[i][j];
        }
    }

    long long maxval = 0;
    for (long i = 0; i < n; i++)
    {
        maxval = max(maxval, dp[0][i]);
    }
    cout << maxval << endl;

    return 0;
}