class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1;
        map<char,char> mp2;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(!mp1[s[i]]){
                if(mp2[t[i]]){
                    return false;
                }
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }else if(mp1[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};
