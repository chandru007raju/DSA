#include <bits/stdc++.h>
using namespace std;
int trailingZeroes(int N)
{
    int cntFive = 0;
    int i = 5;

    while (i <= N)
    {
        cntFive += N / i;
        i *= 5;
    }
    return cntFive;
}

int main()
{
    int n;
    cin >> n;
    int ans = trailingZeroes(n);
    cout << ans;
}