class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        vector<string> phrase;
        string tmp = "";
        for(int i = 0; i < len; i++){
            if(s[i]!= ' '){
                tmp += s[i];
            }else{
                if(tmp.size() > 0){
                    phrase.push_back(tmp);
                    tmp = "";
                }else{
                    continue;
                }
            }
        }
        if(tmp.size()>0){
            phrase.push_back(tmp);
        }
        string res;
        int phsize = phrase.size();
        for(int i = phsize-1; i > 0; i--){
            res+=phrase[i];
            res+=" ";
        }
        res+=phrase[0];
        return res;
    }
};
