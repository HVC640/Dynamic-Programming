class Solution
{
public:
    // Solution 1 Using Recursion TC : O(2^n) TLE, SC : O(n)
    /*
    int rec(int i, int j, vector<vector<int>> grid){
        int m = grid.size(), n = grid[0].size();
        if(i == m-1 && j == n-1) return grid[i][j];
        int right = INT_MAX, down = INT_MAX;
        if(j != n-1) right = grid[i][j] + rec(i, j+1, grid);
        if(i != m-1) down = grid[i][j] + rec(i+1, j, grid);
        return min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        return rec(0, 0, grid);
    }
    */

    // Solution 2 Using Recursion with Memoization TC : O(m*n) TLE, SC : O(m*n+m*n)
    /*
    vector<vector<int>> dp;
    int rec(int i, int j, vector<vector<int>> grid){
        int m = grid.size(), n = grid[0].size();
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int right = INT_MAX, down = INT_MAX;
        if(j != n-1) right = grid[i][j] + rec(i, j+1, grid);
        if(i != m-1) down = grid[i][j] + rec(i+1, j, grid);
        return dp[i][j] = min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        return rec(0, 0, grid);
    }
    */

    // Solution 3 Dynamic Programming with Tabulization TC : O(m*n), SC : O(m*n)
    /*
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp;
        dp.resize(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i != 0) up = grid[i][j] + dp[i-1][j];
                    if(j != 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
    */

    // Solution 4 Optimal Solution TC : O(m*n), SC : O(n)
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp;
        dp.resize(n, -1);
        for (int i = 0; i < m; i++)
        {
            int left = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = grid[i][j];
                    left = dp[j];
                }
                else
                {
                    int cUP = INT_MAX, cLeft = INT_MAX;
                    if (i != 0)
                        cUP = grid[i][j] + dp[j];
                    if (j != 0)
                        cLeft = grid[i][j] + left;
                    dp[j] = min(cUP, cLeft);
                    left = dp[j];
                }
            }
        }
        return dp[n - 1];
    }
};