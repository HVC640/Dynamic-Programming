#include <bits/stdc++.h>
// Solution 1 using Recursion TC : O(2^m*n) TLE, SC : O(m*n)
/*
int rec(int i, int j, vector<vector<int>>& triangle){
    int n = triangle.size();
    if(i >= n) return 0;
    int down = INT_MAX, diag = INT_MAX;
    down = triangle[i][j] + rec(i+1, j, triangle);
    diag = triangle[i][j] + rec(i+1, j+1, triangle);
    return min(down, diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    return rec(0, 0, triangle);
}
*/

// Solution 2 Recursion with Memoization TC : O(m*n), SC : O(m*n + m*n)
/*
int rec(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp){
    int n = triangle.size();
    if(i >= n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int down = INT_MAX, diag = INT_MAX;
    down = triangle[i][j] + rec(i+1, j, triangle, dp);
    diag = triangle[i][j] + rec(i+1, j+1, triangle, dp);
    return dp[i][j] = min(down, diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return rec(0, 0, triangle, dp);
}
*/

// Solution 3 DP with Tabulization TC : O(m*n), SC : O(m*n)
/*
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i+1; j++){
            if(i == n-1) dp[i][j] = triangle[i][j];
            else{
                int diag = INT_MAX, down = INT_MAX;
                down = triangle[i][j] + dp[i+1][j];
                diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }
    }
    return dp[0][0];
}
*/

// Solution 4 Optimal Solution TC : O(m*n), SC : O(n)
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> dp(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (i == n - 1)
                dp[j] = triangle[i][j];
            else
            {
                int diag = INT_MAX, down = INT_MAX;
                down = triangle[i][j] + dp[j];
                diag = triangle[i][j] + dp[j + 1];
                dp[j] = min(down, diag);
            }
        }
    }
    return dp[0];
}