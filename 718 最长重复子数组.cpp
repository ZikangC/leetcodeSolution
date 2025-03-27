#一般做这种最长的子数组的时候都是考虑最后一个值
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int res = 0;
        vector<vector<int>> dp(len1,vector<int>(len2,0));
        for(int i = 0; i < len2; i++){
            if(nums1[0] == nums2[i]){
                dp[0][i] = 1;   
                res = max(res, dp[0][i]);
            }
        }
        for(int i = 0; i < len1; i++){
            if(nums2[0] == nums1[i]){
                dp[i][0] = 1;   
                res = max(res, dp[i][0]);
            }
        }

        for(int i = 1 ; i < len1; i++){
            for(int j = 1; j < len2; j++){
                if(nums1[i]!=nums2[j]){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
