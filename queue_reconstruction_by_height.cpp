// You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

// Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

// Example 1:

// Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
// Explanation:
// Person 0 has height 5 with no other people taller or the same height in front.
// Person 1 has height 7 with no other people taller or the same height in front.
// Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
// Person 3 has height 6 with one person taller or the same height in front, which is person 1.
// Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
// Person 5 has height 7 with one person taller or the same height in front, which is person 1.
// Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

class Solution {
public:
//         logic behind solving this problem is that number of empty spaces to be left before inserting the element so that  
        static bool cmp(vector<int> &p1,vector<int> &p2)
        {
                if(p1[0]<p2[0])
                {
                        return true;
                }
                if(p1[0]==p2[0])
                {
                        if(p1[1]>p2[1])
                        {
                                return true;
                        }
                }
                return false;              
        }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            
            int n=people.size();
            
            sort(people.begin(),people.end(),cmp);
            
            vector<vector<int>> ans(n,vector<int> ());
            
            for(int i=0;i<people.size();i++)
            {
                    int j,cnt;
                    for(j=0,cnt=0;j<ans.size();j++)
                    {
                            if(ans[j].empty())
                            {
                                    if(cnt==people[i][1]){
                                            break;
                                    }
                                    cnt++;
                            }
                    }
                    ans[j]=people[i];
            }
        return ans;
    }
};