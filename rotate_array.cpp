// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    // The reason because of which my code is failing is due that when the poiter comes to the first position ,it is nothing but you are doing the same job once again ,
    // There is a need to shift the position of the curr when it reaches into the starting index.

       int temp =nums[0];
       int i=0,j=0,start=0;
       int n = nums.size();

       while(j<n)
       {
           do{
                int temp2 = nums[(i+k)%n];
                nums[(i+k)%n]=temp;
                temp= temp2;
                j++;
                i= (i+k)%n;
           }while(i!=start);
           start++;
           i=start;
           temp=nums[start];

       }
        
    }
};