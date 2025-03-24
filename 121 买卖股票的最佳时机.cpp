## 这个题可以考虑用动态规划 但是我还不太会
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0;
        int min = INT_MAX;
        for(int i = 0; i < len; i++){
            if(prices[i] < min){
                min = prices[i];
            }else if(prices[i] - min > res){
                res = prices[i] - min;
            }
        }
        return res;
    }
};
