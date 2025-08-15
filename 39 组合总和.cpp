class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& out,vector<int>& candidates, int begin,int sum,int target){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(out);
            return;
        }
        for(int i = begin; i < candidates.size(); i++){
            out.push_back(candidates[i]);
            sum+= candidates[i];
            backtrack(res,out,candidates,i,sum,target);
            sum-=candidates[i];
            out.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        int sum = 0;
        backtrack(res,out,candidates,0,sum,target);
        return res;

    }
};
