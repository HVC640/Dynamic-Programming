#include <bits/stdc++.h>

// Solution 1 Using Recursion TC : O(2^n) TLE, SC : O(n)
int recursion(int i, int sum1, int sum2, vector<int> &nums)
{
    int n = nums.size();
    if (i >= n)
        return abs(sum2 - sum1);

    int pick = INT_MAX;
    if (sum2 - nums[i] >= 0)
        pick = recursion(i + 1, sum1 + nums[i], sum2 - nums[i], nums);
    int notPick = recursion(i + 1, sum1, sum2, nums);

    return min(pick, notPick);
}

// Solution 2 Using Dynamic Programming With Tabulization TC : O(n * totalSum + totalSum), SC : O(n * totalSum)
int minSubsetSumDifference(vector<int> &nums, int n)
{
    int target = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (nums[0] <= target)
        dp[0][nums[0]]++;

    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= target; k++)
        {
            int pick = 0;
            if (nums[i] <= k)
                pick += dp[i - 1][k - nums[i]];
            int notPick = dp[i - 1][k];

            dp[i][k] = pick + notPick;
        }
    }

    int res = INT_MAX;
    for (int i = target; i >= 0; i--)
    {
        if (dp[n - 1][i])
            res = min(res, abs(target - 2 * i));
    }
    return res;
}

/*
totalSum
sum1
sum2 = totalSum - sum1

sum2 - sum1 = totalSum - 2 * sum1

[1]
ans = 1

[1,2]
ans = 1
*/
