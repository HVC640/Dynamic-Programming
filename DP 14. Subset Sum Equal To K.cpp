// Solution 1 Using Recursion TC : O(2^n), SC : O(n)
/*
bool rec(int index, int k, vector<int> arr){
    int n = arr.size();
    if(index >= n){
        if(k == 0) return true;
        return false;
    }
    bool pick = rec(index+1, k-arr[index], arr);
    bool notPick = rec(index+1, k, arr);
    return (pick || notPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return rec(0, k, arr);
}
*/

// Solution 2 Using Recursion with Memoization TC : O(n*k), SC : O(n*k + n*k)
/*
int rec(int index, int k, vector<int> arr, vector<vector<int>> &dp){
    int n = arr.size();
    if(k < 0) return 0;
    if(index >= n){
        if(k == 0) return 1;
        return 0;
    }
    if(dp[index][k] != -1) return (dp[index][k]);
    int pick = rec(index+1, k-arr[index], arr, dp);
    int notPick = rec(index+1, k, arr, dp);
    return dp[index][k] = (pick || notPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return (rec(0, k, arr, dp)) ? true : false;
}
*/

// Solution 3 DP with Tabulization TC : O(n*k), SC : O(n*k)
/*
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int i = 1; i < n; i++){
        for(int target = 1; target <= k; target++){
            bool notPick = dp[i-1][target];
            bool pick = false;
            if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
            dp[i][target] = pick || notPick;
        }
    }
    return dp[n-1][k];
}
*/

// Solution 4 Optimal Solution TC : O(n*k), SC : O(k)
/*
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false), curr(k+1, false);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    for(int i = 1; i < n; i++){
        for(int target = 1; target <= k; target++){
            bool notPick = prev[target];
            bool pick = false;
            if(arr[i] <= target) pick = prev[target-arr[i]];
            curr[target] = pick || notPick;
        }
        prev = curr;
    }
    return curr[k];
}
*/
