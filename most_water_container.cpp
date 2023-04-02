// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{

    int n = height.size();
    int l = 0, r = n - 1;
    int res = 0;

    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            res = max(res, height[l] * (r - l));
            l++;
        }
        else
        {
            res = max(res, height[r] * (r - l));
            r--;
        }
    }
    return res;
}
int main()
{
    vector<int> arr;
    maxArea(arr);
}