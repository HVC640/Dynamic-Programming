class Solution
{
public:
    // Just Recursion will have TC : O(3^m * 3^m), SC : O(m)
    // Solution 1 Recursion with Memoization TC : O(m*n*n*9) TLE, SC : O(m+m*n*n)
    /*
    int rec(int i, int j1, int j2, vector<vector<int>> grid, vector<vector<vector<int>>>& dp){
        int m = grid.size(), n = grid[0].size();
        if(j1 < 0 || j2 < 0 || j1 > n-1 || j2 > n-1) return -1e9;
        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e9;
        for(int dj1 = -1; dj1 < 2; dj1++){
            for(int dj2 = -1; dj2 < 2; dj2++){
                if(j1 == j2) maxi = max(maxi, grid[i][j1]+rec(i+1, j1+dj1, j2+dj2, grid, dp));
                else maxi = max(maxi, grid[i][j1]+grid[i][j2]+rec(i+1, j1+dj1, j2+dj2, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return rec(0, 0, n-1, grid, dp);
    }
    */

    // Solution 2 DP with Tabulization TC : O(n*n + m*n*n*9), SC : O(m*n*n)
    /*
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 < n; j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }

        for(int i = m-2; i >= 0; i--){
            for(int j1 = 0; j1 < n; j1++){
                for(int j2 = 0; j2 < n; j2++){
                    int maxi = -1e9;
                    for(int dj1 = -1; dj1 < 2; dj1++){
                        for(int dj2 = -1; dj2 < 2; dj2++){
                            if(j1 == j2){
                                int curri = -1e9;
                                if(j1+dj1 >=0 && j1+dj1 < n && j2+dj2 >=0 && j2+dj2 < n) curri = grid[i][j1]+dp[i+1][j1+dj1][j2+dj2];
                                maxi = max(maxi, curri);
                            }
                            else{
                                int curri = -1e9;
                                if(j1+dj1 >=0 && j1+dj1 < n && j2+dj2 >=0 && j2+dj2 < n) curri = grid[i][j1]+grid[i][j2]+dp[i+1][j1+dj1][j2+dj2];
                                maxi = max(maxi, curri);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
    */

    // Solution 3 Optimal Solution TC : O(n*n + m*n*n*9), SC : O(n*n)
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> front(n, vector<int>(n, -1));
        vector<vector<int>> newFront(n, vector<int>(n, -1));

        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                if (j1 == j2)
                    front[j1][j2] = grid[m - 1][j1];
                else
                    front[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < n; j1++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 < 2; dj1++)
                    {
                        for (int dj2 = -1; dj2 < 2; dj2++)
                        {
                            if (j1 == j2)
                            {
                                int curri = -1e9;
                                if (j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)
                                    curri = grid[i][j1] + front[j1 + dj1][j2 + dj2];
                                maxi = max(maxi, curri);
                            }
                            else
                            {
                                int curri = -1e9;
                                if (j1 + dj1 >= 0 && j1 + dj1 < n && j2 + dj2 >= 0 && j2 + dj2 < n)
                                    curri = grid[i][j1] + grid[i][j2] + front[j1 + dj1][j2 + dj2];
                                maxi = max(maxi, curri);
                            }
                        }
                    }
                    newFront[j1][j2] = maxi;
                }
            }
            front = newFront;
        }
        return front[0][n - 1];
    }
};