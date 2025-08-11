class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int tmp = nums[0];
        vector<vector<int>> match;
        match.push_back({nums[0],1});
        int index = 0;
        for(int i = 1; i < len; i++){
            if(nums[i] == tmp){
                match[index][1]++;
            }else{
                index++;
                tmp = nums[i];
                match.push_back({tmp,1});
            }
        }
        sort(match.begin(),match.end(),cmp);
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(match[i][0]);
        }
        return res;
    }
};
