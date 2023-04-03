// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        bool hasZero = false;

        int n = nums.size();

        int l=0,r=0,max_cnt=0;

        while(r<n)
        {
            if(!hasZero && nums[r]==0)
            {
                hasZero=true;
            }
            else if(hasZero && nums[r]==0)
            {
                while(l<=r)
                {
                    if(nums[l]==0)
                    {
                        l++;
                        break;
                    }
                    l++;
                }
            }
            max_cnt= max(max_cnt,(r-l));       
            r++;  
        }   

        return max_cnt;   
        
    }
};