class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = s.size();
        int aimlen = p.size();
        unordered_map<char,int> mp;
        vector<int> res;
        for(auto i:p){
            if(!mp.count(i)){
                mp[i] = 1;
            }else{
                mp[i]++;
            }
        }
        for(int i = 0; i < aimlen; i++){
            if(mp.count(s[i])){
                mp[s[i]]--;
            }
        }
        for(int j = 0; j < aimlen;j++){
            if(mp[p[j]] != 0){
                break;
            }
            if(j == aimlen-1){
                res.push_back(0);
            }
        }
        
        for(int i = 0; i < len - aimlen; i++){
            if(mp.count(s[i])){
                mp[s[i]]++;
            }
            if(mp.count(s[i+aimlen])){
                mp[s[i+aimlen]]--;
            }
            for(int j = 0; j < aimlen;j++){
                if(mp[p[j]] != 0){
                    break;
                }
                if(j == aimlen-1){
                    res.push_back(i+1);
                }
            }
        }
        return res;
    }
};
