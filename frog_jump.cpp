#include <bits/stdc++.h>

using namespace std;

bool helper(vector<int> &stones, int k, int ind)
{

    if (ind >= stones.size())
    {
        return false;
    }

    if (ind == stones.size() - 1)
    {
        return true;
    }

    bool ans = false;

    for (int i = k - 1; i <= (k + 1); i++)
    {
        int num = stones[ind] + i;
        auto it = find(stones.begin(), stones.end(), num);

        if (it != stones.end())
        {
            int index = it - stones.begin();
            ans |= helper(stones, i, index);
        }
    }

    return ans;
}
int main()
{

    int n;
    cin >> n;
    vector<int> stones;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        stones.push_back(a);
    }

    cout<<helper(stones, 1, 0);
}
