class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int res = 1;
        int cnt = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] > nums[i-1]){
                cnt++;
            }else{
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);
        return res;
    }
};
