// You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

// We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

// nums1[i] == nums2[j], and
// the line we draw does not intersect any other connecting (non-horizontal) line.
// Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

// Return the maximum number of connecting lines we can draw in this way.

 

// Example 1:


// Input: nums1 = [1,4,2], nums2 = [1,2,4]
// Output: 2
// Explanation: We can draw 2 uncrossed lines as in the diagram.
// We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.


class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        int m=nums2.size();

        vector<int> prev(m+1,0);

        for(int i=1;i<=n;i++)
        {
            vector<int> cur(m+1,0);
            for(int j=1;j<=m;j++)
            {
                if(nums2[j-1]==nums1[i-1])
                {
                    cur[j]=prev[j-1]+1;
                }
                else
                {
                    cur[j]=max(cur[j-1],prev[j]);
                }
            }
            prev=cur;
        }

        return prev[m];        
    }
};