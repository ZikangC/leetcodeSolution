class Solution {
public:
    static bool cp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),cp);
        int len = intervals.size();
        int cnt = 0;
        int cmp = intervals[0][1];
        for(int i = 1; i < len; i++){
            if(intervals[i][0] < cmp){
                cnt++;
                cmp = min(cmp,intervals[i][1]);
            }else{
                cmp = intervals[i][1];
            }
        }
        return cnt;
    }
};
