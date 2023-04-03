// Given a string s. Return all the words vertically in the same order in which they appear in s.
// Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
// Each word would be put on only one column and that in one column there will be only one word.

 class Solution {
public:
   
   vector<string> printVertically(string s) {
    s+= " "; //adding space at the end for easy calculation of chunk strings.
    vector<string> temp;  //here we will store the chunks of string s after removing extra spaces.
    vector<string> ans;  //this vector will be used for storing answer strings.
    string str = "";
    int maxi = INT_MIN;  //we also need to store the maximum length of all string for adding spaces in our ans strings becuase this will define the size of our ans vector.
    for(int i =0 ; i<s.length(); i++)
    {
        if(s[i]==' ')
        {
            temp.push_back(str);
            int sz = str.size();
            maxi = max(sz,maxi);
            str = "";
        }
        else str += s[i];
    }
    
    for(int i = 0; i<maxi; i++)
    {
        for(auto &it: temp)
        {
            if(i >= it.length()) str += " ";
            else str += it[i];
        }
        int n = str.size()-1;  //storing the length of current string.
        while(str[n]==' ')  //this loop is for removing extra spaces from the end.
        {
            str.pop_back();
            n--;
        }
        ans.push_back(str);
        str = "";
    }
    return ans;
}
};

