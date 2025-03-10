##记得在使用映射的时候查找元素用count函数
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int len = s.size();
        s.push_back(' ');
        map<char,string> mp1;
        map<string,char> mp2;
        string cmp;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i <= len){
            if(s[i]!= ' '){
                cmp.push_back(s[i]);
                i++;
            }else{
                if(mp1.count(pattern[j])){
                    if(mp1[pattern[j]]!=cmp){
                        return false;
                    }
                }else{
                    if(mp2.count(cmp)){
                        return false;
                    }
                    mp1[pattern[j]] = cmp;
                    mp2[cmp] = pattern[j];
                }
                cmp = "";
                cnt++;
                j++;
                i++;
            }
        }
        if(pattern.size()!=cnt){
            return false;
        }
        return true;
    }
};
