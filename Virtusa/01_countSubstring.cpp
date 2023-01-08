// abc --> 5

#include <bits/stdc++.h>
using namespace std;

int countSubstr(string s, int n)
{
    int ans = (n * (n + 1)) / 2;
    int aI = 0, bI = 0, cI = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
        {
            aI = i + 1;
            ans -= min(bI, cI);
        }
        else if (s[i] == 'b')
        {
            bI = i + 1;
            ans -= min(aI, cI);
        }

        else
        {
            cI = i + 1;
            ans -= min(aI, bI);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();

    cout << countSubstr(s, n);
    return 0;
}