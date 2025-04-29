class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int left,right;
        vector<vector<int>> res;
        for(int fir = 0 ; fir < len-3; fir++){
            while(fir > 0 && nums[fir] == nums[fir-1]){
                fir++;
            }
            for(int sec = fir+1; sec < len - 2; sec++){
                if (sec > fir + 1 && nums[sec] == nums[sec - 1]) {
                    continue;
                }
                left = sec+1;
                right = len - 1;
                while(left < right){
                    long sum = (long)nums[fir] + nums[sec] + nums[left] + nums[right];
                    if(sum > target){
                        right--;
                    }else if(sum < target){
                        left++;
                    }else{
                        res.push_back({nums[fir],nums[sec],nums[left],nums[right]});
                        while(left < right && nums[left + 1] == nums[left]){
                            left++;
                        }
                        while(left < right && nums[right - 1] == nums[right]){
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }       
        return res;
    }
};
