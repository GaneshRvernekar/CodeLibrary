// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        int res=0,k=nums.size();
        for(int i=k-1;i>=0;i--)
        {
            int hi=i-1,lo=0;
            while(lo<hi)
            {
                if(nums[lo]+nums[hi]>nums[i])
                {
                    res+=(hi-lo);
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }
        return res;
        
    }
};