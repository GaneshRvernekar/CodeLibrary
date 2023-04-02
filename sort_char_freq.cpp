// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 class Solution {

public:
    bool sort_the_map(pair<char,int> &first1,pair<char,int> &second1)
    {
        return first1.second>second1.second;
    }


    string frequencySort(string s) {

        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]]++;
            }
            else{
                mp[s[i]]=1;
            }
        }

        sort(mp.begin(),mp.end(),sort_the_map);

        string ans;

        for(auto it=mp.begin();it!=mp.end();it++)
        {
            string ans2;
            while(it.second()>0)
            {
                ans2 = ans2+it.first;
            }
            ans= ans+ans2;
        }

        return ans;
    }
};