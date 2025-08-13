class Solution {
public:
    bool check(vector<char>& dif,unordered_map<char,int>& mp){
        for(auto i : dif){
            if(mp[i] > 0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        unordered_map<char,int> mp;
        vector<char> dif;
        for(auto i : t){
            if(!mp.count(i)){
                mp[i] = 1;
                dif.push_back(i);
            }else{
                mp[i]++;
            }
        }
        int l = 0;
        int r = 0;
        int begin = l;
        int res = INT_MAX;
        for(int i = 0; i < slen; i++){
            if(mp.count(s[i])){
                mp[s[i]]-- ;
            }
            while(check(dif,mp)){
                while(!mp.count(s[l])){
                    l++;
                }
                if(i-l+1 < res){
                    begin = l;
                    res = i-l+1;
                }
                mp[s[l]]++;
                l++;
            }
        }
        if(l == 0){
            return "";
        }
        return s.substr(begin,res);
    }
};
