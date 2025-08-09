class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        long int minval = nums[0];
        long int maxval = nums[0];
        long int ans = nums[0];
        int len = nums.size();
        
        for (int i = 1; i < len; i++) {  // 从 i = 1 开始
            int mx = maxval, mn = minval;
            maxval = max(mx * nums[i], max(mn * nums[i], nums[i]));
            minval = min(mx * nums[i], min(mn * nums[i], nums[i]));
            ans = max(ans, maxval);
        }
        
        return ans;
    }
};
