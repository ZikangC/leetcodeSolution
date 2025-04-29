class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp12;
        unordered_map<int,int> mp34;
        int len = nums1.size();
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                mp12[nums1[i] + nums2[j]]++;
                mp34[nums3[i] + nums4[j]]++;
            }
        }
        int sum = 0;
        for(auto i:mp12){
            if(mp34.count(0 - i.first)){
                sum+=mp12[i.first]*mp34[0 - i.first];
            }
        }
        return sum;
    }
};
