// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

 class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max_sum=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum<0)
            {
                sum=0;
            }
            else
            {
                if(sum>max_sum)
                {
                    max_sum=sum;
                }
            }
        }
        return max_sum;
    }
};