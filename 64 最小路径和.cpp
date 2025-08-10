class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum+=grid[0][i];
            dp[0][i] = sum;
        }
        sum = 0;
        for(int j = 0; j < m; j++){
            sum+=grid[j][0];
            dp[j][0] = sum;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
