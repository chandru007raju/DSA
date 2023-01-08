#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (!nums.size())
        return 0;
    sort(begin(nums), end(nums));
    int maxLen = 0, currLen = 1;
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] == nums[i - 1])
            continue;
        else if (nums[i] == nums[i - 1] + 1)
            currLen++;
        else
            maxLen = max(maxLen, currLen), currLen = 1;
    return max(maxLen, currLen);
}
int main()
{
    string s;
    getline(cin, s);

    int num = 0;
    vector<int> v;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == ' ')
            v.push_back(num), num = 0;
        else
            num = num * 10 + (s[i] - '0');
    v.push_back(num);

    cout << longestConsecutive(v);

    return 0;
}