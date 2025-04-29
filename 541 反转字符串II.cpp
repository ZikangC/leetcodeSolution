class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        char tmp;
        for(int i = 0; i < len; i = i + 2*k){
            int left = i;
            int right = min(len-1, i + k -1);
            while(left < right){
                tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
        }
        return s;
    }
};
