class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i = 0; i < len2; i++){
            dp[0][i+1] = i+1;
        }
        for(int i = 0; i < len1; i++){
            dp[i+1][0] = i+1;
        }
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(word1[i] == word2[j]){
                    dp[i+1][j+1] = dp[i][j];
                }else{
                    dp[i+1][j+1] = min(dp[i][j+1],dp[i+1][j])+1;
                }
            }
        }
        return dp[len1][len2];
    }
};
