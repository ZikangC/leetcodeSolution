#一定要注意是排列还是组合 其中需要更改遍历顺序 并且记得是32位整数
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i = 0; i < target+1; i++){
            for(auto j : nums){
                if(i + j <target+1){
                    dp[i+j] += dp[i];
                }
            }
        }
        return dp[target];
    }
};
