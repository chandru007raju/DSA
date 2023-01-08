#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;

    int a[k][k];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int y = i, x = 0;
        while (y >= 0 && x < k)
            cout << a[x++][y--] << " ";
    }

    for (int j = 1; j < k; j++)
    {
        int y = k - 1, x = j;
        while (y >= 0 && x < k)
            cout << a[x++][y--] << " ";
    }
    return 0;
}