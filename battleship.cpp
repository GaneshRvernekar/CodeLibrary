// Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

// Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

class Solution {
public:
 
void apply_dfs(vector<vector<char>> &board,int m,int n,int i,int j)
{
    
    if(i<0 || i>=n || j<0 ||j>=m || board[i][j]=='.')
    {
        return ;
    }
    board[i][j]='.';
    
    apply_dfs(board,m,n,i+1,j);
    apply_dfs(board,m,n,i-1,j);
    apply_dfs(board,m,n,i,j+1);
    apply_dfs(board,m,n,i,j-1);
}
    int countBattleships(vector<vector<char>>& board) {
        
        int cnt=0;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X')
                {
                    cnt++;
                    apply_dfs(board,m,n,i,j);
                }
            }
        }
        
        return cnt;
    }
};