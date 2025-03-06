class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        int sum = 0;
        int index = 0;
        int left = 0;

        while(sum < target && index < len){
            sum += nums[index];
            index++;
        }
        if(index == len && sum < target){
            return 0;
        }else if(index == len && sum >= target){
            while(sum - nums[left] >= target){
                sum = sum - nums[left];
                left++;
            }
            return index - left;
        }
        left = 0;
        res = index - left;
        while(index < len){
            sum = sum+nums[index];
            while(sum - nums[left] >= target){
                sum = sum - nums[left];
                left++;
            }
            res = min(res,index-left+1);
            index++;
        }
        return res;
    }
};
