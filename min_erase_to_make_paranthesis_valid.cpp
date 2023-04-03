// Given a string s of '(' , ')' and lowercase English characters.

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
 

// Example 1:

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.


class Solution {
public:
    string minRemoveToMakeValid(string s) {

        int open =0,close =0;
        int n = s.length();

        for(int i=0;i<n;i++)
        {
           
            if(s[i]=='(')
            {
                open++;
            }
            if(s[i]==')')
            {
                if( open>0)
                {
                open--;
                }
                else
                {
                     s.erase(s.begin()+i,s.begin()+i+1);
                     i--;
                }
            }
        }
     
        n = s.length();
        open =0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')')
            {
                open++;
            }
            if(s[i]=='(')
            {
                if( open>0)
                {
                    // cout<<i<<"his "<<open<<endl;
                     open--;
                }
                else
                {
                    cout<<i<<endl;
                    s.erase(s.begin()+i,s.begin()+i+1);
                    
                }
            }
        }

        return s;
    }
};