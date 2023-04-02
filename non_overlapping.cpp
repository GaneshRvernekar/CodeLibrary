// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        vector<vector<int>> answer;
       
        sort(intervals.begin(),intervals.end(),[](vector<int> &v1,vector<int> &v2){return v1[1]<v2[1];});
        
        answer.push_back(intervals[0]);
        
        int found=0;
        
        for(int i=1;i<intervals.size();i++)
        {
            if(answer.back()[1]>intervals[i][0])
            {
                found++;
            }
            else
            {
                answer.push_back(intervals[i]);
            }
        }
        return found;
    }
};