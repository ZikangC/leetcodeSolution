class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        int len = s.size();
        q.push(s[0]);
        for(int i = 1; i < len; i++){
            if(s[i] == ')'){
                if(!q.empty() && q.top() == '('){
                    q.pop();
                }else{
                    return false;
                }
            }
            if(s[i] == '}'){
                if(!q.empty() && q.top() == '{'){
                    q.pop();
                }else{
                    return false;
                }
            }
            if(s[i] == ']'){
                if(!q.empty() && q.top() == '['){
                    q.pop();
                }else{
                    return false;
                }
            }
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                q.push(s[i]);
            }
        }
        if(!q.empty()){
            return false;
        }
        return true;
    }
};
