// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

class Solution {
public:
        
//         We should be proud that this was identified by Narayana Pandita
        
//     next permutation is like next higher element than the previous ones .
        
//         we can find the next higher element ,with the help of increasing trend in the numbers from the right side 
        
//    smallest number from the increasing trend(i.e pivot) should actually be replaced with other number greater than that 
        
//      !!!which is that number !!!

//    An just greater element than the pivot in the increasing trend is that number to be considered..
        
    void nextPermutation(vector<int>& nums) {
            int i;
            for(i=nums.size()-2;i>=0;i--)
            {
                    if(nums[i+1]>nums[i])
                    {
                          break;  
                    }
            }
            if(i<0)
            {
                    reverse(nums.begin(),nums.end());
                  
            }
            else
            {
            int k=i;
             for(int i=nums.size()-1;i>=k;i--)
            {
                    if(nums[i]>nums[k])
                    {
                            swap(nums[i],nums[k]);
                            break;
                    }
            }
           sort(nums.begin()+k+1,nums.end());
            }
        
    }
};