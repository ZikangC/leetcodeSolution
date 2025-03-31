class Solution {
public:
    int countSubstrings(string s) {
        int len  = s.size();
        int res = 0;
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i = 0; i < len-1; i++){
            dp[i][i] = 1;
            res++;
            if(s[i+1] == s[i]){
                dp[i][i+1] = 1;
                res++;
            }
        }
        dp[len-1][len-1] = 1;
        res++;
        for(int length = 3; length <= len; length++) {
            for(int i = 0; i <= len-length; i++) {
                int j = i + length - 1;
                if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};
#最后一个循环是这样的时候就是错的 因为比如在检查1 5时 2 4根本没有被检查 所以会出问题
for(int i = 0; i < len; i++){
            for(int j = i + 2; j < len; j++){
                if(s[j] == s[i] && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    res++;
                }
            }
        }
