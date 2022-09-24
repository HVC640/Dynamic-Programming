class Solution
{
public:
    int n;
    // Solution 1 Using Recursion TC : O(2^n (Exponentional)), SC : O(n)
    int recursion(int index, int amt, vector<int> &nums)
    {
        if (amt == 0)
            return 1;

        int res = 0;
        for (int i = index; i < n; i++)
        {
            if (i == index || nums[i] != nums[i - 1])
            {
                if (nums[i] <= amt)
                    res += recursion(i, amt - nums[i], nums);
            }
        }
        return res;
    }
    // Solution 2 Using Recursion With Memoization TC : O(n * target), SC : O(n * target + n)
    int recMemo(int index, int tar, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            return (tar % nums[index] == 0);
        }

        if (dp[index][tar] != -1)
            return dp[index][tar];

        int pick = 0, notPick = 0;
        if (nums[index] <= tar)
            pick = recMemo(index, tar - nums[index], nums, dp);
        notPick = recMemo(index - 1, tar, nums, dp);

        return dp[index][tar] = pick + notPick;
    }
    // Solution 3 Using Tabulization TC : O(n * target), SC : O(n * target)
    int tabulization(int target, vector<int> &nums)
    {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int tar = 0; tar <= target; tar++)
        {
            if (tar % nums[0] == 0)
                dp[0][tar] = 1;
        }

        for (int index = 1; index < n; index++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int pick = 0, notPick = 0;
                if (nums[index] <= tar)
                    pick = dp[index][tar - nums[index]];
                notPick = dp[index - 1][tar];
                dp[index][tar] = pick + notPick;
            }
        }

        return dp[n - 1][target];
    }
    // Solution 4 Space Optimization TC : O(n * target), SC : O(target + target)
    int spaceOptimization(int target, vector<int> &nums)
    {
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        for (int tar = 0; tar <= target; tar++)
        {
            if (tar % nums[0] == 0)
                prev[tar] = 1;
        }

        for (int index = 1; index < n; index++)
        {
            for (int tar = 0; tar <= target; tar++)
            {
                int pick = 0, notPick = 0;
                if (nums[index] <= tar)
                    pick = curr[tar - nums[index]];
                notPick = prev[tar];
                curr[tar] = pick + notPick;
            }
            swap(prev, curr);
        }

        return prev[target];
    }

    int change(int amount, vector<int> &nums)
    {
        n = nums.size();
        return spaceOptimization(amount, nums);
    }
};