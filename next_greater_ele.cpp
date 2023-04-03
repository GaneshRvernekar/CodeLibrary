// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this numbe

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n= nums.size();

        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }

        vector<int> answer(n,-1);
        
        stack<int> st;

        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i] )
            {
                answer[st.top()%n]=nums[i];
                st.pop();
            }
            st.push(i);
        }

        return answer;

    }
};