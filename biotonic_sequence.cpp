#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> nums;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		nums.push_back(a);
	}
	LongestBitonicSequence(nums);
}



	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n= nums.size();
	    
	    vector<int> subset;
	    vector<int> dp(n,0);
	    vector<int> dp2(n,0);
	    
	    subset.push_back(nums[0]);
	    dp[0]=1;
	    dp2[n-1]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        if(subset.back()<nums[i])
	        {
	            subset.push_back(nums[i]);
	        }
	        else
	        {
	            auto it =lower_bound(subset.begin(),subset.end(),nums[i]);
	            subset[it-subset.begin()]=nums[i];
	        }
	        dp[i]=subset.size();
	    }
	    subset.clear();
	    subset.push_back(nums[n-1]);
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        if(subset.back()<nums[i])
	        {
	            subset.push_back(nums[i]);
	        }
	        else
	        {
	            auto it =lower_bound(subset.begin(),subset.end(),nums[i]);
	            subset[it-subset.begin()]=nums[i];
	        }
	        dp2[i]=subset.size();
	    }
	    
	    int bio=0;
	    
	    for(int i=0;i<dp.size();i++)
	    {
	            bio = max(bio,dp[i]+dp2[i]-1);
	    }
	    
	    return bio;
	    
	    
	}