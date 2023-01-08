#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (m.find(target - nums[i]) == m.end())
            m[nums[i]] = i;

        else
            return {m[target - nums[i]], i};
    }
    return {-1, -1};
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
    int target;
    cin >> target;
    vector<int> ans = twoSum(v, target);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}