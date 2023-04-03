// Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.

// Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

class Solution {
public:
//         add the digit place value and the next correspondence value in the digit place if the condition is being satisfied
        
void dfs(int num, int n, int K, vector<int> &res) {
  if (n == 0) 
      res.push_back(num);
  else {
      int dig = num % 10;
      if (dig + K <= 9)
          dfs(num * 10 + dig + K, n - 1, K, res);
      if (K != 0 && dig >= K)
          dfs(num * 10 + dig - K, n - 1, K, res);
    }
}
vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> res;
    for (auto num = 1; num <= 9; ++num) 
        dfs(num, N - 1, K, res);
    return res;
}
};