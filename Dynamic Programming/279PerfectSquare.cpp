class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[0] = 0;
        for (int i = 2; i <= n; i++) {
            int output = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                output = min(output, 1 + dp[i - j * j]);
            }
            dp[i] = output;
        }
        return dp[n];
    }
};