class Solution {
public:
    int tmprob(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        if(len == 1){
            return nums[0];
        }
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
        }

        return dp[len - 1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int len = nums.size();
        vector<int> num1(len-1);
        vector<int> num2(len-1);
        for(int i = 0; i < len-1; i++){
            num1[i] = nums[i];
            num2[i] = nums[i+1];
        }
        return max(tmprob(num1),tmprob(num2));
    }
};
