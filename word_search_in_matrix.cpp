// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


class Solution {
public:
        
    bool dfs(int i,int j,vector<vector<char>> &board,string word,int k)
    {
            if(k==word.size())
            {
                    return true;
            }
            if(i<0 ||i>=board.size() || j<0 || j>=board[0].size() ||board[i][j]!=word[k] ) 
            {
                    return false;
            }
            char c=board[i][j];
            board[i][j]='*';
//             when we traversed into the next row there should not be an situation where next element again comes back to the previous ones as it will be a kind of repatation within it .
//             so that it symbolises that the element is already used during this process 
            bool ret=  (dfs(i+1,j,board,word,k+1)||dfs(i,j+1,board,word,k+1)||dfs(i-1,j,board,word,k+1)||dfs(i,j-1,board,word,k+1));
            board[i][j]=c;
            return ret;
    }
        
        
    bool exist(vector<vector<char>>& board, string word) {
            
            for(int i=0;i<board.size();i++)
            {
                    for(int j=0;j<board[0].size();j++)
                    {
                            if(dfs(i,j,board,word,0))
                            {
                                    return true;
                            }
                    }
            }
            return false;
        
    }
};

