class Solution
{
public:
    // Solution 1 Using Recursion TLE TC : O(2^n), SC : O(n)
    /*
    int rec(int i, int j, vector<vector<int>> grid){
        int m = grid.size(), n = grid[0].size();
        if(i == m-1 && j == n-1) return 1;
        if(i == m || j == n) return 0;
        if(grid[i][j] == 1) return 0;

        grid[i][j] = 1;
        int down = 0, right = 0;
        down = rec(i+1, j, grid);
        right = rec(i, j+1, grid);

        return down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        return rec(0, 0, grid);
    }
    */

    // Solution 2 Using Recursion with Memoization TC : O(m*n), SC : O(m*n+m*n)
    /*
    vector<vector<int>> dp;
    int rec(int i, int j, vector<vector<int>> grid){
        int m = grid.size(), n = grid[0].size();
        if(i == m-1 && j == n-1) return 1;
        if(i == m || j == n) return 0;
        if(grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        grid[i][j] = 1;
        int down = 0, right = 0;
        down = rec(i+1, j, grid);
        right = rec(i, j+1, grid);
        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[m-1][n-1] == 1) return 0;
        dp.resize(m, vector<int>(n, -1));
        return rec(0, 0, grid);
    }
    */

    // Solution 3 Using Dynamic Programming with Tabulization TC : O(m*n), SC : O(m*n)
    /*
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;
        vector<vector<int>> dp;
        dp.resize(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if (grid[i][j] == 1) dp[i][j] = 0;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i - 1][j];
                    if(j > 0) left = dp[i][j - 1];
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[m-1][n-1];
    }
    */

    // Solution 4 Optimal Solution TC : O(m*n), SC : O(n)
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        if (grid[m - 1][n - 1] == 1 || grid[0][0] == 1)
            return 0;
        vector<int> dp;
        dp.resize(n, -1);
        for (int i = 0; i < m; i++)
        {
            int left;
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[j] = 1;
                    left = 1;
                }
                else if (grid[i][j] == 1)
                {
                    dp[j] = 0;
                    left = 0;
                }
                else
                {
                    int up = 0, cLeft = 0;
                    if (i > 0)
                        up = dp[j];
                    if (j > 0)
                        cLeft = left;
                    left = cLeft + up;
                    dp[j] = left;
                }
            }
        }
        return dp[n - 1];
    }
};