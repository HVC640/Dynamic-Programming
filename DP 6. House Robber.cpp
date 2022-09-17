class Solution
{
public:
    // Solution 1 Using Recursion TC : O(2^n) Time Limit Exceeded, SC : O(n+n) Space Limit Exceeded
    /*
    int rec(int index, vector<int> nums){
        if(index == 0) return nums[0];
        if(index < 0) return 0;

        int pick;
        if(index == nums.size()-1){
            int num0 = nums[0];
            nums[0] = 0;
            pick = nums[index] + rec(index-2, nums);
            nums[0] = num0;
        }
        else{
            pick = nums[index] + rec(index-2, nums);
        }

        int notPick = 0 + rec(index-1, nums);

        return max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        return rec(nums.size()-1, nums);
    }
    */

    // Solution 2 Recursion with Memoization TC : O(n+n), SC : O(n+n)
    /*
    int rec(int index, vector<int> nums, vector<int>& dp){
        if(index == 0) return nums[0];
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + rec(index-2, nums, dp);
        int notPick = 0 + rec(index-1, nums, dp);

        return dp[index] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        dp.resize(n, -1);
        int num0 = nums[0];
        nums[0] = 0;
        int pickLast = nums[n-1] + rec(n-3, nums, dp);

        dp.clear();
        dp.resize(n, -1);
        nums[0] = num0;
        int pickFirst = 0 + rec(n-2, nums, dp);

        return max(pickFirst, pickLast);
    }
    */
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        if (n == 3)
            return max(nums[0], max(nums[1], nums[2]));

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        int sumMax = max(prev, prev2);
        int index = 2;
        while (index < n - 1)
        {
            int pick = prev2 + nums[index];
            int notPick = prev + 0;
            int curri = max(pick, notPick);
            sumMax = max(sumMax, curri);
            prev2 = prev;
            prev = curri;
            index++;
        }

        prev2 = 0;
        prev = max(0, nums[1]);
        int sumMax2 = max(prev, prev2);
        index = 2;
        while (index < n - 2)
        {
            int pick = prev2 + nums[index];
            int notPick = prev + 0;
            int curri = max(pick, notPick);
            sumMax2 = max(sumMax2, curri);
            prev2 = prev;
            prev = curri;
            index++;
        }

        return max(sumMax, sumMax2 + nums[n - 1]);
    }
};