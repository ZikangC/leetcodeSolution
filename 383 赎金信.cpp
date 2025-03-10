class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mp[26] = {0};
        int lenran = ransomNote.size();
        int lenmag = magazine.size();
        for(int i = 0; i < lenran; i++){
            mp[ransomNote[i] - 'a']++;
        }
        for(auto i : magazine){
            mp[i - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(mp[i] > 0){
                return false;
            }
        }
        return true;
    }
};
