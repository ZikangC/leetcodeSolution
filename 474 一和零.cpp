##倒序遍历是非常重要的一个技巧 可以避免物品的多次使用
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> num(len,vector<int>(2,0));
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i < len; i++){
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == '0'){
                    num[i][0]++;
                }else{
                    num[i][1]++;
                }
            }
        }
        for(int i = 0; i < len; i++){
            for(int k = m; k >= num[i][0]; k--){
                for(int j = n; j >= num[i][1]; j--){
                    if(dp[k - num[i][0]][j-num[i][1]]>= 0){
                        dp[k][j] =  max(dp[k - num[i][0]][j-num[i][1]]+1,dp[k][j]);  
                    }  
                }
            }
        }
        return dp[m][n];

    }
};
