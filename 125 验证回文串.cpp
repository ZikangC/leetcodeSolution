\\记得数字的情况也要考虑到，其中小写字母ASCII 97-122，大写65-90 数字48-57

class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for(int i = 0; i < s.length(); i++){
            if(s[i] > 64 && s[i] < 91){
                tmp.push_back(s[i]+32);
            }
            else if(s[i] > 96 && s[i] < 123){
                tmp.push_back(s[i]);
            }else if(s[i] > 47 && s[i] < 58){
                tmp.push_back(s[i]);
            }
        }
        int left = 0;
        int right = tmp.length() - 1;
        while(left<=right){
            if(tmp[left] != tmp[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
