class Solution {
public:
    int getsum(vector<int>& nums){
        int sum = 0;
        for(int i : nums){
            sum+=i;
        }
        return sum;
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] <= 0&&k > 0){
                nums[i] = 0 - nums[i];
                k--;
            }
        }
        if(k > 0){
            if( k % 2 == 0){
                return getsum(nums);
            }else{
                int cmp = nums[0];
                for(int i = 0; i < len; i++){
                    if(abs(nums[i]) < cmp){
                        cmp = abs(nums[i]);
                    }
                }
                return getsum(nums) - 2*cmp;
            }
        }
        return getsum(nums);
    }
};
