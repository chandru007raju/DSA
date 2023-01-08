#include <bits/stdc++.h>
using namespace std;
int main()
{// 0 1 1 1 1 1 1 0 1 0 1 1
    int row, col;
    cin >> row >> col;

    int arr[row][col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];

    int max = 0, count = 0, index = 0;
    for (int i = 0; i < row; i++)
    {
        count = 0;
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 1)
                count++;
        }
        if (count > max)
        {
            max = count;
            index = i + 1;
        }
    }

    cout << index;
    return 0;
}
