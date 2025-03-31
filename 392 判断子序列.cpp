class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        int i = 0;
        int j = 0;
        while(i < slen && j < tlen){
            if(s[i] == t[j]){
                i++;
            }
            j++;
        }
        if(i == slen){
            return true;
        }
        return false;
    }
};

#使用dp的方法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        vector<vector<bool>> dp(slen+1,vector<bool>(tlen+1,false));
        for(int i = 0; i <= tlen; i++){
            dp[0][i] = true;
        }
        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= tlen; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[slen][tlen];
    }
};
