# 以结尾来判断
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,1);
        for(int i = 1 ; i < len; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }
        int res = 0;;
        for(int i = 0; i < len; i++){
            res = max(res,dp[i]);
        }
        return res;
    }
};
