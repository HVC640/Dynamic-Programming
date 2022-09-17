// Solution 1 Using DP Recursion with Memoization TC : O(n), SC : (n+n)
/*
void rec(int index, vector<int> nums, vector<int> &dp, int &maxSum){
    if(index < 0) return;

    int tempSum = 0;
    for(int i = index+2; i < nums.size(); i++){
        int currSum = nums[index] + dp[i];
        tempSum = max(tempSum, currSum);
    }

    dp[index] = tempSum;
    maxSum = max(maxSum, tempSum);

    rec(index-1, nums, dp, maxSum);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];
    if(n == 2)return max(nums[0], nums[1]);

    vector<int> dp;
    dp.resize(n, -1);
    dp[n-1] = nums[n-1];
    dp[n-2] = nums[n-2];

    int maxSum = max(nums[n-1], nums[n-2]);

    rec(n-3, nums, dp, maxSum);

    return maxSum;
}
*/

// Solution 2 Using Tabulization TC : O(n), SC : O(n)
/*
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return nums[0];
    if(n == 2)return max(nums[0], nums[1]);

    vector<int> dp;
    dp.resize(n, -1);
    dp[n-1] = nums[n-1];
    dp[n-2] = nums[n-2];

    int maxSum = max(nums[n-1], nums[n-2]);

    for(int i = n-3; i >= 0; i--){
        int tempSum = 0;
        for(int j = i+2; j < n; j++){
            tempSum = max(tempSum, dp[j]+nums[i]);
        }
        dp[i] = tempSum;
        maxSum = max(maxSum, tempSum);
    }

    return maxSum;
}
*/

// Striver Approach Using Recursion TC : O(2^n), SC : O(n)
/*
int rec(int index, vector<int> nums){
    if(index == 0) return nums[0];
    if(index < 0) return 0;

    int pick = nums[index] + rec(index-2, nums);
    int notPick = 0 + rec(index-1, nums);

    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    return rec(nums.size()-1, nums);
}
*/

// Striver Approach with memoization TC : O(n), SC : O(n+n)
/*
int rec(int index, vector<int> nums, vector<int> &dp){
    if(index == 0) return nums[0];
    if(index < 0) return 0;

    if(dp[index] != -1) return dp[index];

    int pick = nums[index] + rec(index-2, nums, dp);
    int notPick = 0 + rec(index-1, nums, dp);

    return dp[index] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp;
    dp.resize(nums.size(), -1);
    return rec(nums.size()-1, nums, dp);
}
*/

// Striver Approach with Tabulization TC : O(n), SC : O(n)
/*
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp;
    dp.resize(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    int sumMax = max(dp[0], dp[1]);
    int index = 2;
    while(index < n){
        int pick = dp[index-2] + nums[index];
        int notPick = dp[index-1] + 0;
        dp[index] = max(pick, notPick);
        sumMax = max(sumMax, dp[index]);
        index++;
    }
    return sumMax;
}
*/

// Striver Approach with Space Optimization TC : O(n), SC : O(1)
// Optimal Solution
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = nums[0];
    int prev = max(nums[0], nums[1]);
    int sumMax = max(prev, prev2);
    int index = 2;
    while (index < n)
    {
        int pick = prev2 + nums[index];
        int notPick = prev + 0;
        int curri = max(pick, notPick);
        sumMax = max(sumMax, curri);
        prev2 = prev;
        prev = curri;
        index++;
    }
    return sumMax;
}