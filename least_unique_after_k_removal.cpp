// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

// Example 1:

// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.


class Solution {
public:
   unordered_map<int, int> memo;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        for(auto i: arr) memo[i]++;
        vector<int> temp;
        for(auto i: memo) temp.push_back(i.second);
        sort(temp.begin(), temp.end());
        for(auto i = 0; i < temp.size(); i++){
            if(k < temp[i]) return temp.size() - i;
            k -= temp[i];
        }
        return 0;
    }
};