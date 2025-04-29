class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        int i = 0;
        int left,right;
        for(int i = 0; i < len-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            right = len - 1;
            left = i+1;
            while(left < right){
                if(nums[left] + nums[right] + nums[i] > 0){
                    right--;
                }else if(nums[left] + nums[right] + nums[i] < 0){
                    left++;
                }else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left+1] == nums[left]){
                        left++;
                    }
                    while(left < right && nums[right-1] == nums[right]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
