// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
            
            vector<int> vec;
            
            vec.push_back(nums[0]);
            int len=1;
            for(int i=1;i<nums.size();i++)
            {
                    if(vec.back()<nums[i])
                    {
                            vec.push_back(nums[i]);
                            len++;
                            if(len==3)
                            {
                                    return true;
                            }
                    }
                    else if(vec[0]>=nums[i])
                    {
                            vec[0]=nums[i];
                    }
                    else if(vec[1]>=nums[i])
                    {
                          vec[1]=nums[i]; 
                    }
            }
            return false;
        
    }
};