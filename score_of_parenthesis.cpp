// Given a balanced parentheses string s, return the score of the string.

// The score of a balanced parentheses string is based on the following rule:

// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
 

// Example 1:

// Input: s = "()"
// Output: 1

class Solution {
public:
    int scoreOfParentheses(string s) {
            
            stack<int> st;
            int sc=0;
            for(int i=0;i<s.size();i++)
            {
                    if(s[i]=='(')
                    {
                         st.push(sc);
                         sc=0;
                    }
                    else
                    {
                          sc=st.top()+max(1,sc*2);
                          st.pop();  
                    }
            }
        return sc;
    }
};