#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void print(vector<int> row)
    {
        for (auto it : row)
            cout << it << " ";
        cout << endl;
    }

    int CountNeg(vector<int> row, int n)
    {
        int lo = 0, hi = n - 1, mid;

        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            if (row[mid] >= 0)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (row[lo] < 0)
            return (n - lo);
        return 0;
    }

    int countNegatives(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int n = grid[0].size(), count = 0;
        for (auto row : grid)
        {
            print(row);
            count += CountNeg(row, n);
        }
        return count;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int ans = obj.countNegatives(grid);
    cout << endl
         << ans;
    return 0;
}