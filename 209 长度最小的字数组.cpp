class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = 0;
        int res = INT_MAX;
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum+=nums[i];
            if(sum >= target){
                while(sum>=target){
                    sum-=nums[left];
                    left++;
                }
                res = min(res,i-left+2);
            }
        }
        if(res == INT_MAX){
            return 0;
        }
        return res;
    }
};
