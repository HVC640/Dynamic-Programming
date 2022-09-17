// Solution 1 Using Recursion TC : O(3^n) TLE, SC : (n)
/*
int rec(int index, int day, vector<vector<int>> &points){
    if(index >= points.size()) return 0;
    int maxPoints = 0;
    for(int i = 0; i < 3; i++) if(i != day) maxPoints = max(maxPoints, points[index][i]+rec(index+1, i, points));
    return maxPoints;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    return rec(0, -1, points);
}
*/

// Solution 2 Using Dynamic Programming Recursion with Memoization TC : O(n*3), SC : O(n+3*n)
/*
int rec(int index, int day, vector<vector<int>> &points, vector<vector<int>>& dp){
    if(index >= points.size()) return 0;
    int maxPoints = 0;
    if(day != -1 && dp[index][day] != -1)return dp[index][day];
    for(int i = 0; i < 3; i++) if(i != day) maxPoints = max(maxPoints, points[index][i]+rec(index+1, i, points, dp));
    if(day != -1) return dp[index][day] = maxPoints;
    return maxPoints;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(points.size(), vector<int>(3, -1));
    return rec(0, -1, points, dp);
}
*/

// Solution 3 Using Dynamic Programming with Tabuliztion TC : O(n*4*3), SC : O(n*4)
/*
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int index = 1; index < n; index++){
        for(int last = 0; last < 4; last++){
            dp[index][last] = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    dp[index][last] = max(dp[index][last], points[index][task]+dp[index-1][task]);
                }
            }
        }
    }
    return dp[n-1][3];
}
*/

// Solution 4 Optimal Solution TC : O(n*4*3), SC : O(1)
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, -1);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int index = 1; index < n; index++)
    {
        vector<int> curri(4, -1);
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    curri[last] = max(curri[last], points[index][task] + prev[task]);
                }
            }
        }
        prev = curri;
    }
    return prev[3];
}