class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res = {};
        int len = nums.size();
        if(len == 1){
            res.push_back(pow(nums[0],2));
            return res;
        }
        int index = 0;
        while(index < len && nums[index] < 0){
            index++;
        }
        int left = index-1;
        while(left >= 0){
            if(index == len||abs(nums[left]) <= abs(nums[index])){
                res.push_back(pow(nums[left],2));
                left--;
            }else{
                res.push_back(pow(nums[index],2));
                index++;
            }
        }
        for(int i = index; i < len; i++){
            res.push_back(pow(nums[i],2));
        }
        return res;
    }
};
