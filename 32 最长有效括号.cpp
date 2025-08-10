class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if(len == 0){
            return 0;
        }
        vector<int> dp(len+1,0);
        for(int i = 2; i < len+1; i++){
            if(s[i-1] == '('){
                dp[i] = 0;
            }else{
                if(s[i-2] == '('){
                    dp[i] = dp[i-2] + 2;
                }
                else if(i - dp[i-1] - 2 >=0 && s[i - dp[i-1] - 2] == '('){
                    dp[i] = dp[i - dp[i-1]-2] + 2 + dp[i-1];
                }
            }
        }
        int res = 0;
        for(int i = 0 ; i < len+1; i++){
            res = max(res,dp[i]);
        }
        return res;

    }
};
