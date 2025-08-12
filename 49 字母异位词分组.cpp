class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<int>> mp(len,vector<int>(26,0));
        vector<int> flag(len,0);
        for(int i = 0; i < len; i++){
            for(auto j : strs[i]){
                mp[i][j-'a']++;
            }
        }
        vector<vector<string>> res;
        vector<string> tmp;
        int index= 0;
        for(int i = 0; i< len; i++){
            tmp = {};
            if(flag[i] == 1){
                continue;
            }else{
                tmp.push_back(strs[i]);
                flag[i] = 1;
            }
            for(int j = i; j < len; j++){
                if(flag[j] == 0){
                    index = 0;
                    for(index = 0; index < 26; index++){
                        if(mp[i][index] != mp[j][index]){
                            break;
                        }
                    }
                    if(index == 26){
                        tmp.push_back(strs[j]);
                        flag[j] = 1;
                    }
                }
            }
            res.push_back(tmp);
        }
        return res;

    }
};
