#只要挣钱就卖
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0;
        for(int i = 1; i < len; i++){
            if(prices[i] > prices[i-1]){
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
};
