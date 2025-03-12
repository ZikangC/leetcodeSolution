class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(mp.count(nums[i])){
                if(i - mp[nums[i]]<=k){
                    return true;
                }else{
                    mp[nums[i]] = i;
                }
            }else{
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};
