// Solution 1 Using Recursion TC : O(Exponential), SC : O(n)
int recursion(int index, int n, vector<int> &price)
{
    if (index == 1)
        return n * price[index - 1];

    int pick = 0, notPick = 0;
    if (index <= n)
        pick = price[index - 1] + recursion(index, n - index, price);
    notPick = 0 + recursion(index - 1, n, price);

    return max(pick, notPick);
}
// Solution 2 Using Recursion With Memoization TC : O(n*n), SC : O(n*n + n)
int recMemo(int index, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 1)
        return n * price[index - 1];

    if (dp[index][n] != -1)
        return dp[index][n];

    int pick = 0, notPick = 0;
    if (index <= n)
        pick = price[index - 1] + recMemo(index, n - index, price, dp);
    notPick = 0 + recMemo(index - 1, n, price, dp);

    return dp[index][n] = max(pick, notPick);
}
// Solution 3 Using Tabulization TC : O(n*n), SC : O(n*n)
int tabulization(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int j = 0; j <= n; j++)
        dp[1][j] = j * price[0];

    for (int index = 1; index <= n; index++)
    {
        for (int j = 0; j <= n; j++)
        {
            int pick = 0, notPick = 0;
            if (index <= j)
                pick = price[index - 1] + dp[index][j - index];
            notPick = 0 + dp[index - 1][j];
            dp[index][j] = max(pick, notPick);
        }
    }
    return dp[n][n];
}
// Solution 4 Optimized Solution TC : O(n*n), SC : O(n*n)
int optimizedSolution(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int j = 0; j <= n; j++)
        prev[j] = j * price[0];

    for (int index = 1; index <= n; index++)
    {
        for (int j = 0; j <= n; j++)
        {
            int pick = 0, notPick = 0;
            if (index <= j)
                pick = price[index - 1] + curr[j - index];
            notPick = 0 + prev[j];
            curr[j] = max(pick, notPick);
        }
        swap(prev, curr);
    }
    return prev[n];
}
int cutRod(vector<int> &price, int n)
{
    return optimizedSolution(price, n);
}