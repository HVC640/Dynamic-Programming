#include <bits/stdc++.h>
int mod = 1e9 + 7;

// Solution 1 Using Recursion TC : O(2^n), SC : O(n)
int recursion(int i, int tar, int d, int totalSum, vector<int> &nums)
{
    int n = nums.size();
    if (i < 0)
    {
        if (totalSum - 2 * tar == d)
            return 1;
        return 0;
    }

    int pick = 0, notPick = 0;
    pick = recursion(i - 1, tar + nums[i], d, totalSum, nums);
    notPick = recursion(i - 1, tar, d, totalSum, nums);

    return ((pick % mod) + (notPick % mod)) % mod;
}

// Solution 2 Using Recursion With Memoization TC : O(n*totalSum), SC : O(n*totalSum + n)
int recMemo(int i, int tar, int d, int totalSum, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (i < 0)
    {
        if (totalSum - 2 * tar == d)
            return 1;
        return 0;
    }

    if (dp[i][tar] != -1)
        return dp[i][tar];

    int pick = 0, notPick = 0;
    pick = recMemo(i - 1, tar + nums[i], d, totalSum, nums, dp);
    notPick = recMemo(i - 1, tar, d, totalSum, nums, dp);

    return dp[i][tar] = ((pick % mod) + (notPick % mod)) % mod;
}

// Solution 3 Using Tabulization TC : O(n*totalSum), SC : O(n*totalSum)
int tabulization(int n, int d, vector<int> &nums)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (nums[0] <= totalSum)
        dp[0][nums[0]] = 1;
    if (nums[0] == 0)
        dp[0][0] = 2;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 0; sum <= totalSum; sum++)
        {
            int pick = 0, notPick = 0;
            if (nums[i] <= sum)
                pick += dp[i - 1][sum - nums[i]];
            notPick = dp[i - 1][sum];
            dp[i][sum] = ((pick % mod) + (notPick % mod)) % mod;
        }
    }

    int res = 0;
    for (int i = 0; i <= totalSum; i++)
    {
        if (totalSum - 2 * i == d)
        {
            res = ((res % mod) + (dp[n - 1][i] % mod)) % mod;
        }
    }
    return res;
}

// Solution 4 Using Optimal Solution TC : O(n*totalSum), SC : O(totalSum + totalSum)
int countPartitions(int n, int d, vector<int> &nums)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    vector<int> curr(totalSum + 1, 0), prev(totalSum + 1, 0);
    prev[0] = 1;
    if (nums[0] <= totalSum)
        prev[nums[0]] = 1;
    if (nums[0] == 0)
        prev[0] = 2;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 0; sum <= totalSum; sum++)
        {
            int pick = 0, notPick = 0;
            if (nums[i] <= sum)
                pick += prev[sum - nums[i]];
            notPick = prev[sum];

            curr[sum] = ((pick % mod) + (notPick % mod)) % mod;
        }
        swap(prev, curr);
    }

    int res = 0;
    for (int i = 0; i <= totalSum; i++)
    {
        if (totalSum - 2 * i == d)
        {
            res = ((res % mod) + (prev[i] % mod)) % mod;
        }
    }
    return res;
}
