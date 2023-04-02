// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> right(n);
        vector<int> left(n);
        
        int j=n-2,i=1;
        left[0]=1;
        right[n-1]=1;
        
        while(i<n)
        {
            left[i]=left[i-1]*nums[i-1];
            i++;
        }
        while(j>=0)
        {
            right[j]=right[j+1]*nums[j+1];
            j--;
        }
        
        vector<int> answer;
        for(int i=0;i<n;i++)
        {
            answer.push_back(right[i]*left[i]);
        }
        return answer;
    }
};