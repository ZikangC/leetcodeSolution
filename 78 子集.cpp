class Solution {
public:
    void backtrack(vector<vector<int>>& res,vector<int>& nums,vector<int>& tmp,int begin){
        res.push_back(tmp);
        if(begin == nums.size()){
            return;
        }
        for(int i =begin; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            for(int j = i; j < nums.size();j++){
                backtrack(res,nums,tmp,j+1);
            }
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp = {};
        backtrack(res,nums,tmp,0);
        return res;
    }
};
