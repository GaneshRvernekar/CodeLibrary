// Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.
 

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[12,21,16],[27,45,33],[24,39,28]]


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] += (i == 0 ? 0 : mat[i - 1][j]) + (j == 0 ? 0 : mat[i][j - 1]) - (i == 0 || j == 0 ? 0 : mat[i - 1][j - 1]);
                
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int r1 = i - k > 0 ? i - k - 1 : -1;
                int r2 = i + k < m ? i + k : m - 1;
                int c1 = j - k > 0 ? j - k - 1 : -1;
                int c2 = j + k < n ? j + k : n - 1;
                dp[i][j] = mat[r2][c2] - (c1 == -1 ? 0 : mat[r2][c1]) - (r1 == -1 ? 0 : mat[r1][c2]) + (r1 == -1 || c1 == -1 ? 0 : mat[r1][c1]);
            }
        }
        return dp;
    }
};