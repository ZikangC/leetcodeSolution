class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int len = s.size();
        int res = 0;
        int curlen = 0;
        int begin = 0;
        for(int i = 0 ; i < len; i++){
            if(!mp.count(s[i]) || mp[s[i]] == 0){
                mp[s[i]] = 1;
                curlen = i-begin+1;
                res = max(res,curlen);
            }else{
                mp[s[i]] = 2;
                while(mp[s[i]]>1){
                    mp[s[begin]] = mp[s[begin]] - 1;
                    begin++;
                }
            }
        }

        return res;
    }
};
