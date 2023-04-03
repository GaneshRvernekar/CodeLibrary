// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

 

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: 
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is at least 2 units of time between any two same tasks.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
            if(n==0)
            {
                    return tasks.size();
            }
            
            unordered_map<char,int> mp;
          int m=0;
                         
            for(int i=0;i<tasks.size();i++)
            {
                    mp[tasks[i]]++;  
                    m=max(mp[tasks[i]],m);
            } 
            int ans=(m-1)*(n+1);
            
            for(auto e : mp)
            {
                  if(e.second==m)
                  {
                          ans++;
                  }
            }
            return max(ans,(int)tasks.size());  
    }
};