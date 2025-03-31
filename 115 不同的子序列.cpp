#思路对了 但是再好好考虑一下状态转移的问题
class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if (tlen == 0) return 1; // 空串是任何字符串的子序列
        if (slen == 0) return 0;
        vector<vector<unsigned long long>> dp(tlen+1,vector<unsigned long long>(slen+1,0));
        for(int j = 0; j <= slen; j++){
            dp[0][j] = 1;
        }
        for(int i = 0; i < tlen; i++){
            for(int j = 0; j < slen; j++){
                if(t[i] == s[j]){
                    dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
                }else{
                    dp[i+1][j+1] = dp[i+1][j];
                }
            }
        }
        return dp[tlen][slen];
    }
};
