class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.size();
        vector<int> dp(26,0);
        vector<int> res;
        for(int i = 0; i < len; i++){
            dp[s[i] - 'a'] = i;
        }
        int curmax = dp[s[0] - 'a'];
        int curpos = 0;
        int maxpos = dp[s[0] - 'a'];
        int i = 0;
        while(curpos < len){
            i = curpos;
            while(i <= curmax){
                if(dp[s[i]-'a']  == len-1){
                    res.push_back(len - curpos);
                    return res;
                }else if(dp[s[i]-'a']  > curmax){
                    curmax = dp[s[i]-'a'];
                }
                i++;
            }
            res.push_back(curmax-curpos+1);
            curpos = curmax + 1;
            curmax = dp[s[curpos] - 'a'];
        }
        return res;
    }
};
