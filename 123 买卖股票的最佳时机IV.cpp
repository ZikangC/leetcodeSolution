# 前后各一遍 然后对应位置相加
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dp(len);
        int curmin = INT_MAX;
        int curmax = -1;
        int res1 = 0;
        int res2 = 0;
        for(int i = 0; i < len; i++){
            if(prices[i] < curmin){
                curmin = prices[i];
            }
            res1 = max(res1,prices[i] - curmin);
            dp[i] = res1;
        }
        for(int i = len-1; i >= 0; i--){
            if(prices[i] > curmax){
                curmax = prices[i];
            }
            res2 = max(res2,curmax - prices[i]);
            dp[i] += res2;
        }
        int res = dp[0];
        for(int i = 0; i < len; i++){
            res = max(res,dp[i]);
        }
        return res;
    }
};
