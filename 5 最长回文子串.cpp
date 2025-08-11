class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i = 0; i < len; i++){
            dp[i][i] = 1;
        }
        int begin = 0;
        int reslen = 1;
        for(int i = 0; i < len; i++){
            for(int l = 0; l < i; l++){
                if(s[l] == s[i] && (l+1 == i || dp[l+1][i-1] == 1)){
                    dp[l][i] = 1;
                    if(i-l+1 > reslen){
                        reslen = i-l+1;
                        begin = l;
                    }
                }
            }
        }
        return s.substr(begin,reslen);
    }
};
