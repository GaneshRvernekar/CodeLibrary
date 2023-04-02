// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.



class Solution {
public:
// This problem also comes similar to the subsequence problem where we take the coin once and leave the coin once 
        int return_number(vector<int> &coin,int target,int index,vector<vector<int>> &dp)
        {
                if(index==0)
                {
                     if(target % coin[index]==0)
                     {
                             return target/coin[index];
                     }
                        return 1e9;
                }
                if(dp[index][target]!=-1)
                {
                        return dp[index][target];
                }
                
                int not_take = return_number(coin,target,index-1,dp);
                
                int take=1e9;
                if(coin[index]<=target)
                {
                take=1+return_number(coin,target-coin[index],index,dp);
                }
                dp[index][target]=min(take,not_take);
                return min(take,not_take);
                
        }
    int coinChange(vector<int>& coins, int amount) {
            
            
            vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
            int ans=return_number(coins,amount,coins.size()-1,dp);
            if(ans>=1e9)
            {
             return -1;       
            }
            else
            { 
                return ans;
            }
        
    }
};