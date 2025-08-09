class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<int> dp(len+1,0);
        dp[0] = 1;
        for(int i = 0; i < len+1; i++){
            for(auto j : wordDict){
                int lenword = j.size();
                if(i >= lenword && dp[i - lenword] == 1 && s.substr(i-lenword,lenword) == j){
                    dp[i] = 1;
                }
            }
        }
        return dp[len];
    }
};
