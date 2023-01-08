#include <bits/stdc++.h>
using namespace std;
int myPow(int x, int y)
{
    double temp;
    if (y == 0)
        return 1;
    temp = myPow(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int power = myPow(a, b);
    int modlPow = power % c;
    cout << modlPow << endl;
    return 0;
}