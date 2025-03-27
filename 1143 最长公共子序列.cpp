#其实思路是差不多的 就是最大的时候一定要记得考虑清楚
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1,vector<int>(len2,0));
        int res = 0;
        if(text1[0] == text2[0]){
            dp[0][0] = 1;
            res = 1;
        }
        for(int i = 1; i < len2; i++){
            if(text1[0] == text2[i]){
                dp[0][i] = 1;
                res = 1;
            }else{
                dp[0][i] = dp[0][i-1];
            }
        }
        for(int i = 1; i < len1; i++){
            if(text1[i] == text2[0]){
                dp[i][0] = 1;
                res = 1;
            }else{
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i = 1; i < len1; i++){
            for(int j = 1; j < len2; j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                    res = max(res,dp[i][j]);
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return res;
    }
};
