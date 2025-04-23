class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int all = words.size();
        int base[26] = {0};
        int tmp[26] = {0};
        memset(base,101,sizeof base);
        for(int i = 0; i < all-1; i++){
            for(auto j : words[i]){
                tmp[j - 'a']++;
            }
            for(int j = 0; j < 26; j++){
                base[j] = min(base[j],tmp[j]);
            }
            for(int p = 0; p < 26; p++){
                tmp[p] = 0;
            }
        }
        vector<string> res;
        for(auto i :words[all-1]){
            if(base[i - 'a'] > 0){
                string stm;
                stm = i;
                res.push_back(stm);
                base[i - 'a']--;
            }
        }
        return res;
    }
};
