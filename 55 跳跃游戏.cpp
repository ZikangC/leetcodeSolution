class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int maxpos = nums[0];
        for(int i = 0; i < len; i++){
            if(i <= maxpos){
                maxpos = max(i + nums[i],maxpos);
            }
        }
        return maxpos >= len-1;
    }
};
