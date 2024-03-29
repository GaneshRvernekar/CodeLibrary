// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


class Solution {
public:
        
        void pair_sum(int index,vector<int>& candidates,vector<int> &ans2, int target,vector<vector<int>> &ans)
        {
                if(index>=candidates.size())
                {
                        return ;
                }
                if(target==0)
                {
                        ans.push_back(ans2);
                        return;
                }
                
                if(target-candidates[index]>=0)
                {
                     ans2.push_back(candidates[index]);
                     pair_sum(index,candidates,ans2,target-candidates[index],ans);  
                       ans2.pop_back();
                }
                pair_sum(index+1,candidates,ans2,target,ans);
                
       }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            
            vector<vector<int>> ans;
            vector<int> ans2;
            pair_sum(0,candidates,ans2,target,ans);
            
            return ans;
        
    }
};