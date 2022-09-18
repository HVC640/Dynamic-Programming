#include <bits/stdc++.h>

// Solution 1 Recursion TC : O(n * 3^m*n), SC : O(m*n)
/*
int rec(int i, int j, vector<vector<int>> matrix){
    int m = matrix.size(), n = matrix[0].size();
    if(i >= m) return 0;
    int leftDiag = INT_MIN, down = INT_MIN, rightDiag = INT_MIN;
    if(j-1 >= 0 && j-1 < n) leftDiag = matrix[i][j] + rec(i+1, j-1, matrix);
    if(j >= 0 && j < n) down = matrix[i][j] + rec(i+1, j, matrix);
    if(j+1 >= 0 && j+1 < n) rightDiag = matrix[i][j] + rec(i+1, j+1, matrix);
    return max(leftDiag, max(down, rightDiag));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int maxi = INT_MIN;
    for(int j = 0; j < n; j++) maxi = max(maxi, rec(0, j, matrix));
    return maxi;
}
*/

// Solution 2 Recursion with Memoization TC : O(n*m*n), SC : O(m*n + m*n)
/*
int rec(int i, int j, vector<vector<int>> matrix, vector<vector<int>> &dp){
    int m = matrix.size(), n = matrix[0].size();
    if(i >= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int leftDiag = INT_MIN, down = INT_MIN, rightDiag = INT_MIN;
    if(j-1 >= 0 && j-1 < n) leftDiag = matrix[i][j] + rec(i+1, j-1, matrix, dp);
    if(j >= 0 && j < n) down = matrix[i][j] + rec(i+1, j, matrix, dp);
    if(j+1 >= 0 && j+1 < n) rightDiag = matrix[i][j] + rec(i+1, j+1, matrix, dp);
    return dp[i][j] = max(leftDiag, max(down, rightDiag));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    int maxi = INT_MIN;
    for(int j = 0; j < n; j++){
        vector<vector<int>> dp(m, vector<int>(n, -1));
        maxi = max(maxi, rec(0, j, matrix, dp));
    }
    return maxi;
}
*/

// Solution 3 DP with Tabulization TC : O(n + m*n), SC : O(m*n)
/*
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for(int i = m-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(i == m-1) dp[i][j] = matrix[i][j];
            else{
                int leftDiag = INT_MIN, down = INT_MIN, rightDiag = INT_MIN;
                if(j-1 >= 0 && j-1 < n) leftDiag = matrix[i][j] + dp[i+1][j-1];
                if(j >= 0 && j < n) down = matrix[i][j] + dp[i+1][j];
                if(j+1 >= 0 && j+1 < n) rightDiag = matrix[i][j] + dp[i+1][j+1];
                dp[i][j] = max(leftDiag, max(down, rightDiag));
            }
        }
    }
    int maxi = INT_MIN;
    for(int j = 0; j < n; j++) maxi = max(maxi, dp[0][j]);
    return maxi;
}
*/

// Solution 4 Optimal Solution TC : O(n + m*n), SC : O(n + n)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(n, -1);
    vector<int> dp2(n, -1);
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == m - 1)
                dp[j] = matrix[i][j];
            else
            {
                int leftDiag = INT_MIN, down = INT_MIN, rightDiag = INT_MIN;
                if (j - 1 >= 0 && j - 1 < n)
                    leftDiag = matrix[i][j] + dp[j - 1];
                if (j >= 0 && j < n)
                    down = matrix[i][j] + dp[j];
                if (j + 1 >= 0 && j + 1 < n)
                    rightDiag = matrix[i][j] + dp[j + 1];
                dp2[j] = max(leftDiag, max(down, rightDiag));
            }
        }
        if (i != m - 1)
            dp = dp2;
    }
    int maxi = INT_MIN;
    for (int j = 0; j < n; j++)
        maxi = max(maxi, dp[j]);
    return maxi;
}