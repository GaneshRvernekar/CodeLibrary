// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.


class Solution {
public:
    vector<int> pass={1,7,30};

    int check(vector<int> &days,vector<int> &costs,int curr,vector<int> &dp)
    {
        if(curr>=days.size())
        {
            return 0;
        }

        if(dp[curr]!=-1)
        {
            return dp[curr];
        }

        int value=INT_MAX;
        for(int i=0;i<3;i++)
        {
            
                int date = days[curr]+pass[i];
                auto num = lower_bound(days.begin(),days.end(),date);
                int ind = num-days.begin();
                value = min(value,costs[i]+check(days,costs,ind,dp));
        }  

        return dp[curr]=value;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1);

        return check(days,costs,0,dp);
        
    }
};