// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
            
           int n= nums.size();
           vector<int>additional(n,-1);
           additional[0]=nums[0];
            
            for(int i=1;i<n;i++)
            {
                    if(i>1)
                    {
                          additional[i]=max(additional[i-1],additional[i-2]+nums[i]);   
                    }
                    else
                    {
                            additional[i]=max(additional[i-1],nums[i]);
                    }
                  
            }
            return additional[n-1];
        
    }
};