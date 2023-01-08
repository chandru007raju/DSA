#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    int cnt1 = 0, cnt2 = 0;

    for (auto i : s)
    {
        if (i == '*')
            cnt1++;
        else if (i == '#')
            cnt2++;
    }
    cout << cnt1 - cnt2 << endl;

    if ((cnt1 - cnt2) < 0)
        cout << abs(cnt1 - cnt2) << " # is required to make string equal.";
    else if ((cnt1 - cnt2) > 0)
        cout << cnt1 - cnt2 << " * is required to make string equal.";
    else
        cout << "Stringf is equal";

    return 0;
}