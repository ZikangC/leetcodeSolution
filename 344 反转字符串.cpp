class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        char tmp;
        int left = 0;
        int right = len - 1;
        while(left < right){
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        return;
    }
};
