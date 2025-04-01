#记得else的情况 不要迷信之前的想法
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len,1));
        int res = 1;
        for(int i = 0; i < len-1; i++){
            dp[i][i] = 1;
            if(s[i+1] == s[i]){
                dp[i][i+1] = 2;
                for(int j = i+1; j < len-1; j++){
                    dp[i][j] = 2;
                }
                res = 2;
            }
        }
        for(int checklen = 3; checklen <= len; checklen++){
            for(int i = 0; i < len-checklen+1; i++){
                if(s[i+checklen-1] == s[i]){
                    dp[i][i+checklen-1] = dp[i+1][i+checklen-2]+2;
                    res = max(res,dp[i][i+checklen-1]);
                }else{
                    dp[i][i+checklen-1] = max(dp[i][i+checklen-2],dp[i+1][i+checklen-1]);
                }
            }
        }
        return res;
    }
};
