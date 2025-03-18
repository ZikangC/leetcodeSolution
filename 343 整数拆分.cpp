#需要考虑复杂更低的解法 当拆出来的内容有大于4时总可以再拆
class Solution {
public:
    int integerBreak(int n) {
        int len = n+1;
        vector<int> dp(len,0);
        if(len == 3){
            return 1;
        }else if(len == 4){
            return 2;
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        int sum = 0;
        for(int i = 4; i < len; i++){
            sum = 0;
            for(int j = 0; j < i; j++){
                sum = max(sum,dp[j]*dp[i-j]);
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};
