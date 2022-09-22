#include <bits/stdc++.h>

// Solution 1 Using Recusion TC : O(2^n) TLE, SC : O(n)
int recursion(int i, int maxWeight, vector<int> &weight, vector<int> &value)
{
    int n = value.size();
    if (i == n)
        return 0;

    int pick = 0, notPick = 0;
    if (weight[i] <= maxWeight)
        pick = value[i] + recursion(i + 1, maxWeight - weight[i], weight, value);
    notPick = recursion(i + 1, maxWeight, weight, value);

    return max(pick, notPick);
}

// Solution 2 Using Recusion With Memoization TC : O(n*maxWeight) TLE, SC : O(n*maxWeight + n)
int recMemo(int i, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    int n = value.size();
    if (i == n)
        return 0;

    if (dp[i][maxWeight] != -1)
        return dp[i][maxWeight];

    int pick = 0, notPick = 0;
    if (weight[i] <= maxWeight)
        pick = value[i] + recMemo(i + 1, maxWeight - weight[i], weight, value, dp);
    notPick = recMemo(i + 1, maxWeight, weight, value, dp);

    return dp[i][maxWeight] = max(pick, notPick);
}

// Solution 3 Using Tabulization TC : O(n*maxWeight) TLE, SC : O(n*maxWeight)
int tabulization(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = maxWeight; j >= 0; j--)
        {
            int pick = 0, notPick = 0;
            if (weight[i] <= j)
                pick = value[i] + dp[i + 1][j - weight[i]];
            notPick = dp[i + 1][j];

            dp[i][j] = max(pick, notPick);
        }
    }

    return dp[0][maxWeight];
}

// Striver's Approach
// Solution 2 Using Recusion With Memoization TC : O(n*maxWeight) TLE, SC : O(n*maxWeight + n)
int recMemoStriver(int i, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    int n = value.size();
    if (i == 0)
    {
        if (maxWeight >= weight[0])
            return value[0];
        return 0;
    }

    if (dp[i][maxWeight] != -1)
        return dp[i][maxWeight];

    int pick = 0, notPick = 0;
    if (weight[i] <= maxWeight)
        pick = value[i] + recMemoStriver(i - 1, maxWeight - weight[i], weight, value, dp);
    notPick = recMemoStriver(i - 1, maxWeight, weight, value, dp);

    return dp[i][maxWeight] = max(pick, notPick);
}

// Solution 4 Using Space Optimiation TC : O(n*maxWeight) TLE, SC : O(maxWeight + maxWeight)
int knapsackStriver(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for (int wt = weight[0]; wt <= maxWeight; wt++)
        dp[0][wt] = value[0];
    for (int i = 1; i < n; i++)
    {
        for (int wt = 0; wt <= maxWeight; wt++)
        {
            int pick = 0, notPick = 0;
            if (weight[i] <= wt)
                pick = value[i] + dp[i - 1][wt - weight[i]];
            notPick = dp[i - 1][wt];
            dp[i][wt] = max(pick, notPick);
        }
    }
    return dp[n - 1][maxWeight];
}

// Solution 4 Using Space Optimiation TC : O(n*maxWeight) TLE, SC : O(maxWeight + maxWeight)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = maxWeight; j >= 0; j--)
        {
            int pick = 0, notPick = 0;
            if (weight[i] <= j)
                pick = value[i] + prev[j - weight[i]];
            notPick = prev[j];

            curr[j] = max(pick, notPick);
        }
        swap(prev, curr);
    }

    return prev[maxWeight];
}