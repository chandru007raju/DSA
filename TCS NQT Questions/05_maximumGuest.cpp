#include <bits/stdc++.h>
using namespace std;
int main()
{   //3,5,2,0 --> In
    //0,2,4,4 --> Out
    int n;
    cin >> n;
    int e[n], l[n];
    for (int i = 0; i < n; i++)
        cin >> e[i];
    for (int i = 0; i < n; i++)
        cin >> l[i];

    int mx = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += e[i] - l[i];
        mx = max(sum, mx);
    }
    cout << mx;
    return 0;
}