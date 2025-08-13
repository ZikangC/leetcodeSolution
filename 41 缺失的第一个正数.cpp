class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int r = len - 1;
        for(int i = 0; i < len; i++){
            if(nums[i] <= 0 || nums[i] > len){
                nums[i] = len+1;
            }
        }
        for(int i = 0; i < len; i++){
            if(nums[i] < len+1 && nums[i] != i+1 && nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
                i--;
            }
        }
        for(int i = 0; i < len; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return len + 1;
    }
};
