class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <sqrt(i) + 1; j++){
                if(pow(j,2) <= i){
                    dp[i] = min(dp[i],dp[i - pow(j,2)]+1);
                }
            }
        }
        return dp[n];
    }
};
