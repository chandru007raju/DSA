// Who is winner

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, x, score;
    vector<int> ans;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        set<int> s;
        score = m;

        for (int j = 0; j < m; j++)
        {
            cin >> x;
            s.insert(x);
        }
        if (s.size() == 4)
            score += 1;
        else if (s.size() == 5)
            score += 2;
        else if (s.size() >= 6)
            score += 4;
        ans.push_back(score);
    }

    int max1 = *max_element(ans.begin(), ans.end());
    int winnerCount = 0;
    int winnerIndex = -1;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == max1)
        {
            winnerCount++;
            winnerIndex = i;
        }
    }

    if (winnerCount >= 2)
        cout << "Tie" << endl;
    else if (winnerCount == 1 && winnerIndex == 0)
        cout << "Radha" << endl;
    else
        cout << winnerIndex + 1 << endl;
    return 0;
}