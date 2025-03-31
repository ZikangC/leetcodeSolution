#其实最大的挑战就是一定要关注数组都为负的情况
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,0);
        int res = nums[0];
        for(int j = 0; j < len; j++){
            if(nums[j] >= 0){
                break;
            }else{
                res = max(res,nums[j]);
            }
            if(j == len-1){
                return res;
            }
        }
        if(nums[0] > 0){
            dp[0] = nums[0];
        }
        for(int i = 1; i < len; i++){
            dp[i] = max(0,dp[i-1] + nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};
