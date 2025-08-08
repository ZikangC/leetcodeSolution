class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 1; i < amount+1; i++){
            for(auto j : coins){
                if(j <= i){
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
        if(dp[amount] == amount+1){
            return -1;
        }else{
            return dp[amount];
        }
        return -1;
    }
};
