#include <bits/stdc++.h>

// Solution 1 Using Recursion TC : O(2^n) TLE, SC : O(n)
int recursion(int i, int tar, vector<int> &nums)
{
    int n = nums.size();
    if (i == 0)
    {
        if (tar == 0 && nums[0] == 0)
            return 2;
        if (tar == 0 || tar == nums[0])
            return 1;
        return 0;
    }

    int pick = 0, notPick = 0;
    if (nums[i] <= tar)
        pick = recursion(i - 1, tar - nums[i], nums);
    notPick = recursion(i - 1, tar, nums);

    return pick + notPick;
}

// Solution 2 Using Recursion With Memoization TC : O(n*tar), SC : O(n*tar + n)
int recMemo(int i, int tar, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (i == 0)
    {
        if (tar == 0 && nums[0] == 0)
            return 2;
        if (tar == 0 || tar == nums[0])
            return 1;
        return 0;
    }

    if (dp[i][tar] != -1)
        return dp[i][tar];

    int pick = 0, notPick = 0;
    if (nums[i] <= tar)
        pick = recMemo(i - 1, tar - nums[i], nums, dp);
    notPick = recMemo(i - 1, tar, nums, dp);

    return dp[i][tar] = pick + notPick;
}

// Solution 3 Using Tabulization TC : O(n*tar), SC : O(n*tar)
int tabulization(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (nums[0] <= tar)
        dp[0][nums[0]] = 1;
    if (nums[0] == 0)
        dp[0][0] = 2;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int pick = 0, notPick = 0;
            if (nums[i] <= sum)
                pick = dp[i - 1][sum - nums[i]];
            notPick = dp[i - 1][sum];

            dp[i][sum] = pick + notPick;
        }
    }

    return dp[n - 1][tar];
}

// Solution 4 Optimal Solution TC : O(n*tar), SC : O(tar)
int findWays(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

    prev[0] = curr[0] = 1;
    if (nums[0] <= tar)
        prev[nums[0]] = 1;
    if (nums[0] == 0)
        prev[0] = 2;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int pick = 0, notPick = 0;
            if (nums[i] <= sum)
                pick = prev[sum - nums[i]];
            notPick = prev[sum];

            curr[sum] = pick + notPick;
        }
        swap(prev, curr);
    }

    return prev[tar];
}
