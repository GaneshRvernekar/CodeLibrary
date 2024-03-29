// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1


class Solution {
public:
    void find_dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j)
    {
         if(i<0 || j<0 || j==grid[0].size() || i==grid.size() || grid[i][j]=='0')
         {
                 return ;
         }
            if(vis[i][j]==0)
            {
                    vis[i][j]=1;
                   find_dfs(grid,vis,i+1,j); 
                   find_dfs(grid,vis,i-1,j);
                   find_dfs(grid,vis,i,j+1);        
                   find_dfs(grid,vis,i,j-1);     
            }
               
                  
            
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
            int island=0;
            for(int i=0;i<grid.size();i++)
            {
                    for(int j=0;j<grid[0].size();j++)
                    {
                            if(vis[i][j]==0 && grid[i][j]=='1')
                            {
                                    island++;
                                  find_dfs(grid,vis,i,j);  
                            }
                    }
            }
            return island;
    }
};