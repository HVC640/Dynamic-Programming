#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Solution 1 Using Recursion with Memoization using dynamic programming TC : O(n), SC : O(n+n)
/*
int rec(int k, vector<int> &heights, vector<int> &dp){
    if(k < 0){
        return 0;
    }
    if(dp[k] == -1){
        int left = abs(heights[k+1] - heights[k]) + dp[k+1];
        int right = abs(heights[k+2] - heights[k]) + dp[k+2];
        dp[k] = min(left, right);
        rec(k-1, heights, dp);
    }
}

int frogJump(int n, vector<int> heights)
{
    vector<int> dp;
    heights.push_back(1001);
    dp.resize(n+1, -1);
    dp[n] = 1001;
    dp[n-1] = 0;
    rec(n-2, heights, dp);
    return dp[0];
}
*/

// Solution 2 Using Tabulation Dynamic Programming TC : O(n), SC : O(n)
/*
int frogJump(int n, vector<int> heights)
{
    vector<int> dp;
    heights.push_back(1001);
    dp.resize(n+1, -1);
    dp[n] = 1001;
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        if(dp[i] == -1){
            int left = abs(heights[i+1] - heights[i]) + dp[i+1];
            int right = abs(heights[i+2] - heights[i]) + dp[i+2];
            dp[i] = min(left, right);
        }
    }
    return dp[0];
}
*/

// Solution 3 Using Tabulation and Space Optimiaztion TC : O(n), SC : O(1)
int frogJump(int n, vector<int> heights)
{
    heights.push_back(1001);
    int prev2 = 1001;
    int prev = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int left = abs(heights[i + 1] - heights[i]) + prev;
        int right = abs(heights[i + 2] - heights[i]) + prev2;
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
