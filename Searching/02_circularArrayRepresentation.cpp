#include <bits/stdc++.h>
using namespace std;
void print(char a[], int n, int ind)
{
    // Need to print the array from given index
    char b[(2 * n)];
    for (int i = 0; i < n; i++)
        b[i] = b[n + i] = a[i];

    for (int i = ind; i < n + ind; i++)
        cout << b[i] << " ";
}

int main()
{
    char a[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n, 3);
    return 0;
}