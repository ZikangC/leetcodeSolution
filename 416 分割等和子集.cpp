class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum+=nums[i];
        }
        if(sum % 2 == 1){
            return false;
        }
        int half = sum/2;
        vector<int> dp(half+1,0);
        dp[0] = 1;
        for(int i = 0; i < len; i++){
            for(int j = half; j >= 0; j--){
                if(j >= nums[i] && dp[j-nums[i]] == 1){
                    dp[j] = 1;
                }
            }
        }
        return dp[half];
    }
};
#一定要记得第二层循环从大到小
