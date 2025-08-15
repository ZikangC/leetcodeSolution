class Solution {
public:
    void backtrack(vector<string>& res, string& out, int left, int right){
        if(left < 0 || right < 0){
            return;
        }
        if(left > right){
            return;
        }
        if(left == 0 && right == 0){
            res.push_back(out);
            return;
        }
        out.push_back('(');
        left--;
        backtrack(res,out,left,right);
        left++;
        out.pop_back();
        out.push_back(')');
        right--;
        backtrack(res,out,left,right);
        right++;
        out.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string out;
        int left = n;
        int right = n;
        backtrack(res,out,left,right);
        return res; 
    }
};
