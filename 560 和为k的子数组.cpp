class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> sum(len+1,0);
        int sumtmp = 0;
        for(int i = 1; i <= len; i++){
            sumtmp+= nums[i-1];
            sum[i] = sumtmp;
        }
        int res = 0;
        for(int i = 0; i < len; i++){
            for(int j = i+1; j < len+1; j++){
                if(sum[j] - sum[i] == k){
                    res++;
                }
            }
        }
        return res;
    }
};
