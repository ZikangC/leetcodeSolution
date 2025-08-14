class Solution {
public:
    void backtrack(vector<string>& res, string& out, string& digits, int i, unordered_map<char,string>& mp){
        if(i == digits.size()){
            if(out.size() != 0){
                res.push_back(out);
            }
            return;
        }
        for(int j = 0; j < mp[digits[i]].size(); j++){
            out.push_back(mp[digits[i]][j]);
            backtrack(res,out,digits,i+1,mp);
            out.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> res;
        string out = "";
        backtrack(res,out,digits,0,mp);
        return res;
    }
};
