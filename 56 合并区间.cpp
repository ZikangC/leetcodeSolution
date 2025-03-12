class Solution {
public:
    static bool cp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cp);
        int len = intervals.size();
        vector<vector<int>> res;
        int cmp;
        int i = 0;
        int j = 0;
        while(i < len){
            res.push_back(intervals[i]);
            cmp = intervals[i][1];
            while(i + 1 < len && intervals[i+1][0] <= cmp){
                cmp = max(cmp,intervals[i+1][1]);
                i++;
            }
            res[j][1] = cmp;
            j++;
            i++;
        }
        return res;
    }
};
