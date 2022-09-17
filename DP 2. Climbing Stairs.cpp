#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // This Problem is nothing but a fibonacci sequence

    // Solution 1 Using Recursion TC : O(2^n) Time Limit Exceeded, SC : O(n)
    int recursion(int index, int n)
    {
        if (index >= n)
        {
            return (index == n) ? 1 : 0;
        }
        return recursion(index + 1, n) + recursion(index + 2, n);
    }

    // Solution 2 Using DP Memoization TC : O(n), SC : O(n+n)
    int recMemo(int index, int n, vector<int> &dp)
    {
        if (index >= n)
        {
            return (index == n) ? 1 : 0;
        }
        if (dp[index] != -1)
            return dp[index];
        return recMemo(index + 1, n, dp) + recMemo(index + 2, n, dp);
    }

    // Solution 3 Using Tabulization TC : O(n), SC : O(n)
    int dpWithTabulization(int n)
    {
        vector<int> fiboDP(n + 1, -1);
        fiboDP[0] = 1;
        fiboDP[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            fiboDP[i] = fiboDP[i - 1] + fiboDP[i - 2];
        }
        return fiboDP[n];
    }

    // Solution 4 Space Optimization TC : O(n), SC : O(1)
    int spaceOptimized(int n)
    {
        int prev2 = 1, prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

    int climbStairs(int n)
    {
        // return recursion(0, n);

        // vector<int> dp(n+2, -1);
        // dp[n] = 1;
        // dp[n+1] = 0;
        // return recMemo(0, n, dp);

        // return dpWithTabulization(n);

        return spaceOptimized(n);
    }
};