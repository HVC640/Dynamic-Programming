/*
bool rec(int index, vector<int> &arr, int totalSum, int currSum, vector<vector<int>> dp){
    if(totalSum/2 == currSum) return true;
    if(index < 0) return false;
    if(dp[index][currSum] != -1) return dp[index][currSum];
    return dp[index][currSum] = rec(index-1, arr, totalSum, currSum+arr[index], dp) || rec(index-1, arr, totalSum, currSum, dp);
}

bool canPartition(vector<int> &arr, int n){
    int totalSum = 0;
    for(int x : arr) totalSum += x;
    if(totalSum % 2) return false;
    vector<vector<int>> dp(n, vector<int>(totalSum+1, -1));
    return rec(n-1, arr, totalSum, 0, dp);
}
*/

bool canPartition(vector<int> &arr, int n)
{
    int totalSum = 0;
    for (int x : arr)
        totalSum += x;
    if (totalSum % 2)
        return false;
    int k = totalSum / 2;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = dp[i - 1][target];
            bool pick = false;
            if (arr[i] <= target)
                pick = dp[i - 1][target - arr[i]];
            dp[i][target] = pick || notPick;
        }
    }
    return dp[n - 1][k];
}