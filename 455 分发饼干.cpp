#这个题你超时了 记得再做一遍
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int leng = g.size();
        int lens = s.size();
        if(lens == 0){
            return 0;
        }
        int res = 0;
        int i = 0;
        int j = 0;
        while(i < leng && j < lens){
            if(s[j] >= g[i]){
                res++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return res;
    }
};
