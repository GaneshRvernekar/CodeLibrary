// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int m=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int k=nums.size()-1;
            int j=i+1;
            while(j<nums.size() &&j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {

                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(k!=0 && nums[k]==nums[k-1])k--;
                    while(j!=n-1 &&nums[j]==nums[j+1])j++;
                    j++;
                    k--;
                    
                }
                else if((nums[i]+nums[j]+nums[k])>0)
                {
                    while(k!=0 && nums[k]==nums[k-1])k--;
                    k--;
                }
                else if((nums[i]+nums[j]+nums[k])<0)
                {
                    while(j!=n-1 &&nums[j]==nums[j+1])j++;
                    j++;
                }
            }
            while(i!=n-1 && nums[i]==nums[i+1])i++;
        }
       for(auto triplet : ans)
            sort(triplet.begin(),triplet.end());
        return ans;
    }