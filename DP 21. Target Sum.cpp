#include <bits/stdc++.h>
// Solution 1 Using Recursion TC : O(2^n) TLE, SC : O(n)
int recursion(int index, int tar, vector<int> &nums)
{
    if (index == 0)
    {
        if (nums[index] == 0 && tar == 0)
            return 2;
        if (tar + nums[index] == 0 || tar - nums[index] == 0)
            return 1;
        return 0;
    }
    return recursion(index - 1, tar + nums[index], nums) + recursion(index - 1, tar - nums[index], nums);
}
// Solution 2 Using Recursion With Memoization TC : O(n * tar) TLE, SC : O(n*tar + n)
int recMemo(int index, int tar, vector<int> &nums, map<pair<int, int>, int> &umap)
{
    if (index == 0)
    {
        if (nums[index] == 0 && tar == 0)
            return 2;
        if (tar + nums[index] == 0 || tar - nums[index] == 0)
            return 1;
        return 0;
    }
    if (umap.find({index, tar}) != umap.end())
        return umap[{index, tar}];
    return umap[{index, tar}] = recMemo(index - 1, tar + nums[index], nums, umap) + recMemo(index - 1, tar - nums[index], nums, umap);
}

// Solution 3 Using Tabulization TC : O(n * tar) TLE, SC : O(n * tar)
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
            dp[i][sum] = pick + notPick;
        }
    }

    int res = 0;
    for (int i = 0; i <= totalSum; i++)
    {
        if (totalSum - 2 * i == d)
        {
            res = res + dp[n - 1][i];
        }
    }
    return res;
}

// Solution 4 Using Space Optimization TC : O(n * tar) TLE, SC : O(tar + tar)
int spaceOptimization(int n, int d, vector<int> &nums)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    vector<int> prev(totalSum + 1, 0), curr(totalSum + 1, 0);
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
            curr[sum] = pick + notPick;
        }
        swap(prev, curr);
    }

    int res = 0;
    for (int i = 0; i <= totalSum; i++)
    {
        if (totalSum - 2 * i == d)
        {
            res = res + prev[i];
        }
    }
    return res;
}

int targetSum(int n, int target, vector<int> &nums)
{
    return spaceOptimization(n, target, nums);
}
