#include <bits/stdc++.h>
using namespace std;
double myPow(double x, int y)
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
    float a;
    int b;
    cin >> a;
    cin >> b;
    float power = myPow(a, b);
    cout<<a<<" ^ "<<b<<" = "<<power<<endl;
    return 0;
}