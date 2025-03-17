class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(len == 2){
            return min(cost[0],cost[1]);
        }
        len = len +1;
        cost.push_back(0);
        int dp[len];
        memset(dp,0,sizeof(dp));
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < len; i++){
            dp[i] = min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
        }
        return dp[len-1];
    }
};
