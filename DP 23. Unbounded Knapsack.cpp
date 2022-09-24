#include <bits/stdc++.h>
// Solution 1 Using Recursion TC : O(Exponential), SC : O(n)
int recursion(int index, int w, vector<int> &profit, vector<int> &weight)
{
    if (index == 0)
    {
        return (weight[index] <= w) ? ((w / weight[index]) * profit[index]) : -1e9;
    }

    int pick = 0, notPick = 0;
    if (weight[index] <= w)
        pick = profit[index] + recursion(index, w - weight[index], profit, weight);
    notPick = recursion(index - 1, w, profit, weight);

    return max(pick, notPick);
}
// Solution 2 Using Recursion With Memoization TC : O(n * wt), SC : O(n * wt + n)
int recMemo(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return (weight[index] <= w) ? ((w / weight[index]) * profit[index]) : -1e9;
    }
    if (dp[index][w] != -1)
        return dp[index][w];
    int pick = 0, notPick = 0;
    if (weight[index] <= w)
        pick = profit[index] + recMemo(index, w - weight[index], profit, weight, dp);
    notPick = recMemo(index - 1, w, profit, weight, dp);

    return dp[index][w] = max(pick, notPick);
}
// Solution 3 Using Tabulization TC : O(n * wt), SC : O(n * wt)
int tabulization(int n, int wt, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(wt + 1, 0));
    for (int w = 0; w <= wt; w++)
    {
        if (weight[0] <= w)
            dp[0][w] = (w / weight[0]) * profit[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= wt; w++)
        {
            int pick = 0, notPick = 0;
            if (weight[index] <= w)
                pick = profit[index] + dp[index][w - weight[index]];
            notPick = dp[index - 1][w];
            dp[index][w] = max(pick, notPick);
        }
    }

    return dp[n - 1][wt];
}
// Solution 4 Using Optimized Solution TC : O(n * wt), SC : O(wt + wt)
int spaceOptimization(int n, int wt, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(wt + 1, 0), curr(wt + 1, 0);
    for (int w = 0; w <= wt; w++)
    {
        if (weight[0] <= w)
            prev[w] = (w / weight[0]) * profit[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= wt; w++)
        {
            int pick = 0, notPick = 0;
            if (weight[index] <= w)
                pick = profit[index] + curr[w - weight[index]];
            notPick = prev[w];
            curr[w] = max(pick, notPick);
        }
        swap(prev, curr);
    }

    return prev[wt];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return spaceOptimization(n, w, profit, weight);
}
