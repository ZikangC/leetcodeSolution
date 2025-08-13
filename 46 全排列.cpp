class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int begin, int len){
        if(begin == len){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < len; i++){
            swap(nums[begin],nums[i]);
            backtrack(res,nums,begin+1,len);
            swap(nums[begin],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        backtrack(res,nums,0,len);
        return res;
    }
};
