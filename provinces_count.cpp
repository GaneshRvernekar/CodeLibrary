// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.



class Solution {
public:
    void find_dfs(vector<int> &vis,vector<vector<int>> &con,int j)
    {
            for(int i=0;i<con.size();i++)
            {
                   if(i!=j && con[j][i]==1 && vis[i]==0)
                   {
                         vis[i]=1;
                         find_dfs(vis,con,i);
                   }
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
          int n=isConnected.size();
          vector<int> vis(n,0);
            int region =0;
          for(int i=0;i<n;i++)
          {
                if(vis[i]==0)
                {
                        region++;
                        vis[i]=1;
                        find_dfs(vis,isConnected,i);
                }
          }
            return region;
        
    }
};