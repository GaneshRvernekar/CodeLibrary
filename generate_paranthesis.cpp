// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 class Solution {
public:
    
    void helper(int open,int close,string a,vector<string> &ans,int n)
    {
        if(a.length()==2*n)
        {
            ans.push_back(a);
            return ;
        }
        if(n>open)
        {
            helper(open+1,close,a+"(",ans,n);
        }
        if(open>close)
        {
            helper(open,close+1,a+")",ans,n);
        }
    }    
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> answer;
        helper(0,0,"",answer,n);
        return answer;
        
    }
};