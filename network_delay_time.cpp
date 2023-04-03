// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

// Example 1:


// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

class Solution {
public:
          vector<pair<int, int>> adj[101];
   void DFS(vector<int> &signal,int curr,int curr_time)
   {
           if(curr_time>=signal[curr])
           {
                   return;
           }
           
           signal[curr]=curr_time;
           
           for(pair<int,int> edge:adj[curr])
           {
                   int time = edge.first;
                   int node = edge.second;
                   DFS(signal,node,time+curr_time);
           }
   }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
            for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj[source].push_back({travelTime, dest});
        }
            
        
        vector<int> signalReceivedAt(n + 1, INT_MAX);
        DFS(signalReceivedAt, k, 0);
        
        int answer = INT_MIN;
        for (int node = 1; node <= n; node++) {
            answer = max(answer, signalReceivedAt[node]);
        }
        
        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};