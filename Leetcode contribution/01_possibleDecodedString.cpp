#include <bits/stdc++.h>
using namespace std;

void decode(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << " ";
        return;
    }

    int digit = s[0] - '1';
    char ch = 'a' + digit;
    decode(s.substr(1), ans + ch);

    if (s.size() >= 2)
    {
        string str = s.substr(0, 2);
        int n = stoi(str);
        if (n <= 26)
        {
            char c = 'a' + (n - 1);
            decode(s.substr(2), ans + c);
        }

        else if (n <= 52)
        {
            char c = 'A' + (n - 27);
            decode(s.substr(2), ans + c);
        }
    }
}

void possibleDecodedString(string s)
{
    string ans = "";
    decode(s, ans);
}

int main()
{
    string s;
    cin >> s;
    possibleDecodedString(s);
    return 0;
}