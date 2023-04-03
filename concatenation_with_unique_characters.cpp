// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.


class Solution {
public:

    bool check_unique(string s)
    {
        set<char> st;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
        }

        return s.size()==st.size();
    }

    int max_ =0;

    void find_dfs(string s,vector<string> &arr,int i)
    {
       
       
        if(!check_unique(s))
        {
            return ;
        }
        
        int a= s.length();
        max_ = max(a,max_);
        
        if(i==arr.size())
        {
            return 0;
        }
              
 
       return max(find_dfs(s+arr[i],arr,i+1),find_dfs(s,arr,i+1));

    }

    int maxLength(vector<string>& arr) {

        find_dfs("",arr,0);

        return max_;
        
    }
};