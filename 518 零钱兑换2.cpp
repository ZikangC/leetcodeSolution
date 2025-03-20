##dp[0] = 1
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<unsigned long long> dp(amount+1);
        dp[0] = 1;
        for(auto j : coins){
            for(int i = 0; i <= amount; i++){
                if(j + i <= amount){
                    dp[j+i] += dp[i];
                }
            }
        }
        return dp[amount];
    }
};
