#include <bits/stdc++.h> 
int n;

//Solution 1 Using Recursion TC : O(2^n), SC : O(n)
int recursion(int index, int tar, vector<int> &nums){
    if(index == 0) return (tar%nums[index] == 0) ? tar/nums[index] : 1e9;
    
    int pick = 1e9, notPick = 1e9;
    if(nums[index] <= tar) pick = 1 + recursion(index, tar-nums[index], nums);
    notPick = recursion(index-1, tar, nums);
    
    return min(pick, notPick);
}

//Solution 2 Using Recursion With Memoization TC : O(n*tar), SC : O(n*tar + n)
int recMemo(int index, int tar, vector<int> &nums, vector<vector<int>> &dp){
    if(index == 0) return (tar%nums[index] == 0) ? tar/nums[index] : 1e9;
    if(dp[index][tar] != -1) return dp[index][tar];
    
    int pick = 1e9, notPick = 1e9;
    if(nums[index] <= tar) pick = 1 + recMemo(index, tar-nums[index], nums, dp);
    notPick = recMemo(index-1, tar, nums, dp);
    
    return dp[index][tar] = min(pick, notPick);
}

//Solution 3 Using Tabulization TC : O(n*tar), SC : O(n*tar)
int tabulization(vector<int> &nums, int target){
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    for(int index = 0; index < n; index++){
        for(int tar = 0; tar <= target; tar++){
            if(index == 0){
                dp[index][tar] = (tar%nums[index] == 0) ? (tar/nums[index]) : 1e9;
                continue;
            }
            int pick = 1e9, notPick = 1e9;
            if(nums[index] <= tar) pick = 1 + dp[index][tar-nums[index]];
            notPick = dp[index-1][tar];
            dp[index][tar] = min(pick, notPick);
        }
    }
    return (dp[n-1][target] == 1e9) ? -1 : dp[n-1][target];
}

//Solution 4 Using Optimal Solution TC : O(n*tar), SC : O(tar + tar)
int optimal(vector<int> &nums, int target){
    vector<int> prev(target+1, 0), curr(target+1, 0);
    for(int index = 0; index < n; index++){
        for(int tar = 0; tar <= target; tar++){
            if(index == 0){
                curr[tar] = (tar%nums[index] == 0) ? (tar/nums[index]) : 1e9;
                continue;
            }
            int pick = 1e9, notPick = 1e9;
            if(nums[index] <= tar) pick = 1 + curr[tar-nums[index]];
            notPick = prev[tar];
            curr[tar] = min(pick, notPick);
        }
        swap(prev, curr);
    }
    return (prev[target] == 1e9) ? -1 : prev[target];
}

int minimumElements(vector<int> &nums, int tar){
    n = nums.size();
    return optimal(nums, tar);
}