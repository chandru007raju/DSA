#include <bits/stdc++.h>
using namespace std;

int Appalling(int n)
{
    stack<int> st;
    while (n % 2 == 0)
    {
        st.push(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            st.push(i);
            n = n / i;
        }
    }

    if (n > 2)
        st.push(n);
    while (!st.empty())
    {
        if (st.top() == 2 || st.top() == 3 || st.top() == 5)
        {
            st.pop();
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    int num;
    cin >> num;
    if (num < 7)
        return num;

    int i = 6, j = 6, n = 2;
    while (i != num)
    {
        j++;
        int x = Appalling(j);
        if (x == 1)
            i++;
    }
    cout << j << endl;
    return 0;
}