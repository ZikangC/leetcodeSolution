class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int len1 = nums1.size();
        for(int i = 0; i < len1; i++){
            mp[nums1[i]] = 1;
        }
        int len2 = nums2.size();
        vector<int> res;
        for(int j = 0; j < len2; j++){
            if(mp.count(nums2[j]) && mp[nums2[j]] == 1){
                res.push_back(nums2[j]);
                mp[nums2[j]]++ ;
            }
        }
        return res;
    }
};
