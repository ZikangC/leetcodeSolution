class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        unordered_map<int,int> mp;
        for(int i = 0; i < len; i++){
            mp[nums[i]] = 1;
        }
        int res = 1;
        int left = 0;
        int leftsearch;
        int rightsearch;
        int right = 0;
        int tmp;
        for(long int i = 0; i < len; i++){
            if(mp[nums[i]] == 1){
                leftsearch = nums[i] - 1;
                left = 0;
                right = 0;
                rightsearch = nums[i] + 1;
                while(mp.count(leftsearch) && mp[leftsearch] == 1){
                    left++;
                    mp[leftsearch] = 2;
                    leftsearch--;
                }
                while(mp.count(rightsearch) && mp[rightsearch] == 1){
                    right++;
                    mp[rightsearch] = 2;
                    rightsearch++;
                }
                tmp = left+right+1;
                res = max(res,tmp);
            }
        }
        return res;
    }
};
