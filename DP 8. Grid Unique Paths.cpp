class Solution
{
public:
    // Solution 1 Using Dynamic Programing with Memoization TC : O(m*n), SC : O(m*n+m*n)
    /*
    vector<vector<int>> dp;
    int rec(int cRow, int cCol, int m, int n){
        if(cRow == m-1 && cCol == n-1) return 1;
        if(dp[cRow][cCol] != -1) return dp[cRow][cCol];
        int right = 0, down = 0;
        if(cRow != m-1) right = rec(cRow+1, cCol, m, n);
        if(cCol != n-1) down = rec(cRow, cCol+1, m, n);
        return dp[cRow][cCol] = down+right;
    }
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        return rec(0, 0, m, n);
    }
    */

    // Solution 2 Dynamic Programming Using Tabulization TC : O(m*n), SC : O(m*n)
    /*
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        dp.resize(m, vector<int>(n, -1));
        for(int cRow = 0; cRow < m; cRow++){
            for(int cCol = 0; cCol < n; cCol++){
                if(cRow == 0 && cCol == 0) dp[cRow][cCol] = 1;
                else{
                    int right = 0, down = 0;
                    if(cRow != 0) right = dp[cRow-1][cCol];
                    if(cCol != 0) down = dp[cRow][cCol-1];
                    dp[cRow][cCol] = right + down;
                }
            }
        }
        return dp[m-1][n-1];
    }
    */
    // Solution 3 Optimal Solution TC : O(m*n), SC : O(n)
    int uniquePaths(int m, int n)
    {
        vector<int> dp;
        dp.resize(n, -1);
        int left = 1;
        for (int cRow = 0; cRow < m; cRow++)
        {
            for (int cCol = 0; cCol < n; cCol++)
            {
                if (cRow == 0 && cCol == 0)
                    dp[cCol] = 1;
                else
                {
                    int right = 0, down = 0;
                    if (cCol != 0)
                        right = left;
                    if (cRow != 0)
                        down = dp[cCol];
                    left = right + down;
                    dp[cCol] = left;
                }
            }
        }
        return dp[n - 1];
    }
};