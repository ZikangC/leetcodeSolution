class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len,0);
        int sum = 1;
        for(int i = 1; i < len; i++){
            sum = sum*nums[i-1];
            ans[i] = sum;
        }
        int R = 1;
        for(int i = len - 2; i > 0; i--){
            R = R* nums[i + 1];
            ans[i] = ans[i] * R;
        }
        ans[0] = R * nums[1];
        return ans;
    }
};
